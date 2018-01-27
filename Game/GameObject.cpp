//
// Created by terde on 03.02.2017.
//

#include "stdafx.h"
#include "GameObject.h"

namespace gameengine {
    void GameObject::Draw(TransformData parent_transform_data) {
        sf::Transform transform;

		TransformData acc_transform;
		acc_transform.Rotation = rotation + parent_transform_data.Rotation;
		acc_transform.Position = sf::Vector2f(x + parent_transform_data.Position.x, y + parent_transform_data.Position.y);
		acc_transform.Scale = sf::Vector2f(scale_x * parent_transform_data.Scale.x, scale_y * parent_transform_data.Scale.y);

		if (animation_controller != nullptr) {
			auto animation = animation_controller->GetCurrentAnimation();
			if (animation != nullptr) {
				acc_transform.Rotation += animation->GetCurrentTransform().TransformData.Rotation;
				acc_transform.Position += animation->GetCurrentTransform().TransformData.Position;
				acc_transform.Scale.x *= animation->GetCurrentTransform().TransformData.Scale.x;
				acc_transform.Scale.y *= animation->GetCurrentTransform().TransformData.Scale.y;
			}
		}

        transform.translate(acc_transform.Position.x, acc_transform.Position.y);
        transform.rotate(acc_transform.Rotation, pivot_x, pivot_y);
        transform.scale(acc_transform.Scale.x, acc_transform.Scale.y, pivot_x, pivot_y);

        sf::RenderStates renderStates(transform);

		vector<shared_ptr<sf::Drawable>>::iterator shapeIter;
        for (shapeIter = shapes.begin(); shapeIter != shapes.end(); shapeIter++)
            render_window.draw(**shapeIter, renderStates);

		sort(childs.begin(), childs.end(),
			[](const shared_ptr<GameObject> &lhs, const shared_ptr<GameObject> &rhs) {
			return lhs->Depth() < rhs->Depth();
		});

		vector<shared_ptr<GameObject>>::iterator gameObjectIter;
        for (gameObjectIter = childs.begin(); gameObjectIter != childs.end(); gameObjectIter++)
            (*gameObjectIter)->Draw(acc_transform);


    }

    void GameObject::Update() {
		vector<shared_ptr<GameObject>>::iterator iter;
        for (iter = childs.begin(); iter != childs.end(); iter++)
            (**iter).Update();

		if (animation_controller != nullptr)
			animation_controller->Update();

		auto is_mouse_on_object = IsMouseOn();
		HandleMouseOnEvent(is_mouse_on_object);
		HandleOnClickEvent(is_mouse_on_object);
		HandleMouseOutEvent(is_mouse_on_object);
    }

    void GameObject::AddChild(shared_ptr<GameObject> child) {
        child->Init(resource_manager);
        child->Parent(this);
        childs.push_back(child);
    }

    void GameObject::AddShape(shared_ptr<sf::Drawable> shape) {
        shapes.push_back(shape);
    }

    void GameObject::Move(sf::Vector2f delta) {
        x+=delta.x;
        y+=delta.y;
    }

    void GameObject::SwapDepth(GameObject *game_object) {
        int temp_depth = game_object->Depth();
        game_object->Depth(depth);
        depth=temp_depth;
    }

    void GameObject::SetPosition(sf::Vector2f new_position) {
        x = new_position.x;
        y = new_position.y;
    }

    void GameObject::Rotate(float value) {
        rotation+=value;
    }

    void GameObject::SetScale(sf::Vector2f scale) {
        scale_x = scale.x;
        scale_y = scale.y;
    }

    void GameObject::SetPivotPoint(sf::Vector2f pivotPoint) {
        pivot_x = pivotPoint.x;
        pivot_y = pivotPoint.y;
    }

    void GameObject::AddSilhouette(shared_ptr<Silhouette> silhouette) {
        silhouettes.push_back(silhouette);
    }

    bool GameObject::IsMouseOn() {
		vector<shared_ptr<Silhouette>>::iterator silhouetteIter;
        for (silhouetteIter = silhouettes.begin(); silhouetteIter != silhouettes.end(); silhouetteIter++)
            if((*silhouetteIter)->IsMouseOn(render_window))
                return true;

        return false;
    }

    void GameObject::HandleMouseOnEvent(bool is_mouse_on_object) {
        if(!is_mouse_on && is_mouse_on_object) {
			is_mouse_on = true;
			OnMouseOn();
        }
    }

	void GameObject::HandleOnClickEvent(bool is_mouse_on_object) {
		if (is_mouse_on) {
			
		}
	}

	void GameObject::HandleMouseOutEvent(bool is_mouse_on_object) {
		if (is_mouse_on && !is_mouse_on_object) {
			is_mouse_on = false;
			OnMouseOff();
		}
	}

	void GameObject::OnPressed() {}
	void GameObject::OnMouseOn() {}
	void GameObject::OnMouseOff() {}
}
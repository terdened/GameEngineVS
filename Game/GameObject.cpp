//
// Created by terde on 03.02.2017.
//

#include "stdafx.h"
#include "GameObject.h"

namespace gameengine {

    void GameObject::Draw(TransformData parentTransformData) {
        sf::Transform transform;

		TransformData accTransform;
		accTransform.Rotation = rotation + parentTransformData.Rotation;
		accTransform.Position = sf::Vector2f(x + parentTransformData.Position.x, y + parentTransformData.Position.y);
		accTransform.Scale = sf::Vector2f(scale_x * parentTransformData.Scale.x, scale_y * parentTransformData.Scale.y);

		if (animation_controller != nullptr) {
			auto animation = animation_controller->GetCurrentAnimation();
			if (animation != nullptr) {
				accTransform.Rotation += animation->GetCurrentTransform().TransformData.Rotation;
				accTransform.Position += animation->GetCurrentTransform().TransformData.Position;
				accTransform.Scale.x *= animation->GetCurrentTransform().TransformData.Scale.x;
				accTransform.Scale.y *= animation->GetCurrentTransform().TransformData.Scale.y;
			}
		}

        transform.translate(accTransform.Position.x, accTransform.Position.y);
        transform.rotate(accTransform.Rotation, pivot_x, pivot_y);
        transform.scale(accTransform.Scale.x, accTransform.Scale.y, pivot_x, pivot_y);


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
            (*gameObjectIter)->Draw(accTransform);


    }

    void GameObject::Update() {
		vector<shared_ptr<GameObject>>::iterator iter;
        for (iter = childs.begin(); iter != childs.end(); iter++)
            (**iter).Update();

		if (animation_controller != nullptr)
			animation_controller->Update();

		auto isMouseOnObject = IsMouseOn();
		HandleMouseOnEvent(isMouseOnObject);
		HandleOnClickEvent(isMouseOnObject);
		HandleMouseOutEvent(isMouseOnObject);
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

    void GameObject::SwapDepth(GameObject *gameObject) {
        int tempDepth = gameObject->Depth();
        gameObject->Depth(depth);
        depth=tempDepth;
    }

    void GameObject::SetPosition(sf::Vector2f newPosition) {
        x = newPosition.x;
        y = newPosition.y;
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

    void GameObject::HandleMouseOnEvent(bool isMouseOnObject) {
        if(!is_mouse_on && isMouseOnObject) {
			is_mouse_on = true;
			OnMouseOn();
        }
    }

	void GameObject::HandleOnClickEvent(bool isMouseOnObject) {
		if (is_mouse_on) {
			
		}
	}

	void GameObject::HandleMouseOutEvent(bool isMouseOnObject) {
		if (is_mouse_on && !isMouseOnObject) {
			is_mouse_on = false;
			OnMouseOff();
		}
	}


	void GameObject::OnPressed()
		{	}
	void GameObject::OnMouseOn()
		{	}
	void GameObject::OnMouseOff()
		{	}
}
//
// Created by terde on 03.02.2017.
//

#include "stdafx.h"
#include "GameObject.h"

namespace GameEngine {

    void GameObject::Draw(TransformData parentTransformData) {
        sf::Transform transform;

		TransformData accTransform;
		accTransform.Rotation = rotation + parentTransformData.Rotation;
		accTransform.Position = sf::Vector2f(x + parentTransformData.Position.x, y + parentTransformData.Position.y);
		accTransform.Scale = sf::Vector2f(scaleX * parentTransformData.Scale.x, scaleY * parentTransformData.Scale.y);

		if (animation != nullptr) {
			accTransform.Rotation += animation->GetCurrentTransform().TransformData.Rotation;
			accTransform.Position += animation->GetCurrentTransform().TransformData.Position;
			accTransform.Scale.x *= animation->GetCurrentTransform().TransformData.Scale.x;
			accTransform.Scale.y *= animation->GetCurrentTransform().TransformData.Scale.y;
		}

        transform.translate(accTransform.Position.x, accTransform.Position.y);
        transform.rotate(accTransform.Rotation, pivotX, pivotY);
        transform.scale(accTransform.Scale.x, accTransform.Scale.y, pivotX, pivotY);


        sf::RenderStates renderStates(transform);

		vector<shared_ptr<sf::Drawable>>::iterator shapeIter;
        for (shapeIter = shapes.begin(); shapeIter != shapes.end(); shapeIter++)
            renderWindow.draw(**shapeIter, renderStates);

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

		if (animation != nullptr)
			animation->Update();

		auto isMouseOnObject = IsMouseOn();
		HandleMouseOnEvent(isMouseOnObject);
		HandleOnClickEvent(isMouseOnObject);
		HandleMouseOutEvent(isMouseOnObject);
    }

    void GameObject::AddChild(shared_ptr<GameObject> child) {
        child->Init(resourceManager);
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
        scaleX = scale.x;
        scaleY = scale.y;
    }

    void GameObject::SetPivotPoint(sf::Vector2f pivotPoint) {
        pivotX = pivotPoint.x;
        pivotY = pivotPoint.y;
    }

    void GameObject::AddSilhouette(shared_ptr<Silhouette> silhouette) {
        silhouettes.push_back(silhouette);
    }

    bool GameObject::IsMouseOn() {
		vector<shared_ptr<Silhouette>>::iterator silhouetteIter;
        for (silhouetteIter = silhouettes.begin(); silhouetteIter != silhouettes.end(); silhouetteIter++)
            if((*silhouetteIter)->IsMouseOn(renderWindow))
                return true;

        return false;
    }

    void GameObject::HandleMouseOnEvent(bool isMouseOnObject) {
        if(!isMouseOn && isMouseOnObject) {
			isMouseOn = true;
			OnMouseOn();
        }
    }

	void GameObject::HandleOnClickEvent(bool isMouseOnObject) {
		if (isMouseOn) {
			
		}
	}

	void GameObject::HandleMouseOutEvent(bool isMouseOnObject) {
		if (isMouseOn && !isMouseOnObject) {
			isMouseOn = false;
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
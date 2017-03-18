//
// Created by terde on 03.02.2017.
//

#ifndef GAME_GAMEOBJECT_H
#define GAME_GAMEOBJECT_H

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <list>
#include "ResourceManager.h"
#include "Silhouette.h"
#include "Animation.h"

using namespace std;

namespace GameEngine {
    class GameObject {
    private:
        list<shared_ptr<sf::Drawable>> shapes;
        list<shared_ptr<GameObject>> childs;
        list<shared_ptr<Silhouette>> silhouettes;
        float rotation;
        float scaleX;
        float scaleY;
        int depth;
        string name;
        float pivotX;
        float pivotY;
        bool isMouseOn;
        void HandleMouseOnEvent(bool isMouseOnObject);
        void HandleOnClickEvent(bool isMouseOnObject);
        void HandleMouseOutEvent(bool isMouseOnObject);
    protected:
        GameObject* parent = nullptr;
        float x;
        float y;
        sf::RenderWindow& renderWindow;
        ResourceManager* resourceManager;
		virtual void OnPressed();
		virtual void OnMouseOn();
		virtual void OnMouseOff();
		Animation* animation;
    public:
        //creation functions
        GameObject(sf::RenderWindow& app): renderWindow(app), x(0), y(0), depth(0), name("untitled"), rotation(0),
                                           scaleX(1), scaleY(1), pivotX(0), pivotY(0), isMouseOn(false), animation(nullptr)
            {    }
        virtual void Init(ResourceManager* resourceManager) = 0;

        //time erase functions
        void Draw(TransformData parentTransformData);
        virtual void Update();

        //structure functions
        void AddChild(shared_ptr<GameObject> child);
        void AddShape(shared_ptr<sf::Drawable> shape);
        void AddSilhouette(shared_ptr<Silhouette> silhouette);

        //field accessors
		float GlobalX() {
			if (parent == nullptr)
				return  x;
			return parent->x + x;
		}
		float GlobalY() {
			if (parent == nullptr)
				return  y;
			return parent->y + y;
		}

		float GlobalRotation() {
			if (parent == nullptr)
				return  rotation;
			return parent->rotation + rotation;
		}
		float GlobalScaleX() {
			if (parent == nullptr)
				return  scaleX;
			return parent->scaleX * scaleX;
		}
		float GlobalScaleY() {
			if (parent == nullptr)
				return  scaleY;
			return parent->scaleY * scaleY;
		}

        float X() {
            return x;
        }
        void X(float value) {
            x = value;
        }
        void Parent(GameObject* parent){
            this->parent = parent;
        }
        float Y() {
            return y;
        }
        void Y(float value) {
            y = value;
        }
        float Rotation() {
            return rotation;
        }
        void Rotation(float value) {
            rotation = value;
        }
        float ScaleX() {
            return scaleX;
        }
        void ScaleX(float value) {
            scaleX = value;
        }
        float ScaleY() {
            return scaleY;
        }
        void ScaleY(float value) {
            scaleY = value;
        }

        float PivotX() {
            return pivotX;
        }
        void PivotX(float value) {
            pivotX = value;
        }

        float PivotY() {
            return pivotY;
        }
        void PivotY(float value) {
            pivotY = value;
        }

        int Depth() {
            return depth;
        }
        void Depth(int value) {
            depth = value;
        }
        string Name() {
            return name;
        }
        void Name(string value) {
            name = value;
        }

        //Modificators
        void Move(sf::Vector2f delta);
        void SwapDepth(GameObject* gameObject);
        void SetPosition(sf::Vector2f newPosition);
        void Rotate(float value);
        void SetScale(sf::Vector2f scale);
        void SetPivotPoint(sf::Vector2f pivotPoint);
        bool IsMouseOn();

		void PlayAnimation(Animation* animation) {
			this->animation = animation;
		}
    };
}


#endif //GAME_GAMEOBJECT_H

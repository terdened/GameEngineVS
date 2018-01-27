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
#include "AnimationController.h"

using namespace std;

namespace gameengine {
    class GameObject {
    private:
		vector<shared_ptr<sf::Drawable>> shapes;
        vector<shared_ptr<GameObject>> childs;
		vector<shared_ptr<Silhouette>> silhouettes;
        float rotation;
        float scale_x;
        float scale_y;
        int depth;
        string name;
        float pivot_x;
        float pivot_y;
        bool is_mouse_on;
        void HandleMouseOnEvent(bool is_mouse_on_object);
        void HandleOnClickEvent(bool is_mouse_on_object);
        void HandleMouseOutEvent(bool is_mouse_on_object);
    protected:
        GameObject* parent = nullptr;
        float x;
        float y;
        sf::RenderWindow& render_window;
        ResourceManager* resource_manager;
		virtual void OnPressed();
		virtual void OnMouseOn();
		virtual void OnMouseOff();
		AnimationController* animation_controller;
    public:
        GameObject(sf::RenderWindow& app)
			: render_window(app), 
			  x(0), 
			  y(0), 
			  depth(0), 
			  name("untitled"), 
			  rotation(0),
              scale_x(1), 
			  scale_y(1), 
			  pivot_x(0), 
			  pivot_y(0), 
			  is_mouse_on(false), 
			  animation_controller(nullptr) {}

        virtual void Init(ResourceManager* resource_manager) = 0;

        //time erase functions
        void Draw(TransformData parent_transform_data);
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
				return  scale_x;
			return parent->scale_x * scale_x;
		}
		float GlobalScaleY() {
			if (parent == nullptr)
				return  scale_y;
			return parent->scale_y * scale_y;
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
            return scale_x;
        }
        void ScaleX(float value) {
            scale_x = value;
        }
        float ScaleY() {
            return scale_y;
        }
        void ScaleY(float value) {
            scale_y = value;
        }

        float PivotX() {
            return pivot_x;
        }
        void PivotX(float value) {
            pivot_x = value;
        }

        float PivotY() {
            return pivot_y;
        }
        void PivotY(float value) {
            pivot_y = value;
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
        void SwapDepth(GameObject* game_object);
        void SetPosition(sf::Vector2f new_position);
        void Rotate(float value);
        void SetScale(sf::Vector2f scale);
        void SetPivotPoint(sf::Vector2f pivot_point);
        bool IsMouseOn();

		//void PlayAnimation(Animation* animation) {
			//delete this->animation;
			//this->animation = animation;
		//}
    };
}


#endif //GAME_GAMEOBJECT_H

//
// Created by terde on 22.02.2017.
//

#include "stdafx.h"
#include "logo.h"
#include "texture-resource.h"
#include "logo-animation-controller.h"

using namespace sf;

void Logo::Update() {
    GameObject::Update();
}

void Logo::Init(ResourceManager* resource_manager) {
	SpriteGameObject::Init(resource_manager);
	animation_controller = new LogoAnimationController();
}
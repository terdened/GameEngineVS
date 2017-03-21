//
// Created by terde on 22.02.2017.
//

#include "stdafx.h"
#include "Logo.h"
#include "TextureResource.h"
#include "LogoAnimationController.h"

using namespace sf;

void Logo::Update() {
    GameObject::Update();
}

void Logo::Init(ResourceManager* resourceManager) {
	SpriteGameObject::Init(resourceManager);
	animationController = new LogoAnimationController();
}
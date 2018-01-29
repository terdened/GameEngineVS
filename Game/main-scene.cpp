//
// Created by terde on 15.02.2017.
//

#include "stdafx.h"
#include "main-scene.h"

#include "field.h"
#include "ResourceManager.h"
#include "logo.h"
#include "main-scene-resource-loader.h"
#include "walk-around-field-animation.h"

using namespace sf;

void MainScene::Update() {
    Scene::Update();
}

void MainScene::Init() {
    resource_manager = new ResourceManager(nullptr);
    resource_loader = new MainSceneResourceLoader(resource_manager);
    resource_loader->Load();

    auto field = std::make_shared<Field>(render_window);
    field->SetPosition(sf::Vector2f(350, 150));
    AddChild(field);

    auto logo = std::make_shared<Logo>(render_window, "logo");
    AddChild(logo);
    logo->SetScale(sf::Vector2f(0.5f, 0.5f));
	//logo->PlayAnimation(new WalkAroundFieldAnimation());
}
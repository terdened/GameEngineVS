//
// Created by terde on 15.02.2017.
//

#include "stdafx.h"
#include "MainScene.h"

#include "Field.h"
#include "ResourceManager.h"
#include "Logo.h"
#include "MainSceneResourceLoader.h"
#include "WalkAroundFieldAnimation.h"

using namespace sf;

void MainScene::Update() {
    Scene::Update();
}

void MainScene::Init() {
    resourceManager = new ResourceManager(nullptr);
    resourceLoader = new MainSceneResourceLoader(resourceManager);
    resourceLoader->Load();

    Field *field = new Field(renderWindow);
    field->SetPosition(sf::Vector2f(350, 150));
    AddChild(field);

    auto logo = new Logo(renderWindow, "logo");
    AddChild(logo);
    logo->SetScale(sf::Vector2f(0.5f, 0.5f));
	logo->PlayAnimation(new WalkAroundFieldAnimation());
}
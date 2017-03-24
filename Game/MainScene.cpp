//
// Created by terde on 15.02.2017.
//

#include "stdafx.h"
#include "MainScene.h"

#include "Field.h"
#include "ResourceManager.h"
#include "MainSceneResourceLoader.h"

using namespace sf;

void MainScene::Update() {
    Scene::Update();
}

void MainScene::Init() {
    resourceManager = new ResourceManager(nullptr);
    resourceLoader = new MainSceneResourceLoader(resourceManager);
    resourceLoader->Load();

    auto field = std::make_shared<Field>(renderWindow);
    field->SetPosition(sf::Vector2f(350, 50));
    AddChild(field);
}
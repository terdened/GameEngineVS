//
// Created by terde on 15.02.2017.
//

#include "stdafx.h"
#include "Scene.h"
namespace GameEngine {
    void Scene::Draw() {
        list<GameObject*>::iterator gameObjectIter;
        for (gameObjectIter = childs.begin(); gameObjectIter != childs.end(); gameObjectIter++)
            (**gameObjectIter).Draw(sf::Transform());
    }

    void Scene::Update() {
        list<GameObject*>::iterator gameObjectIter;
        for (gameObjectIter = childs.begin(); gameObjectIter != childs.end(); gameObjectIter++)
            (**gameObjectIter).Update();
    }

    void Scene::AddChild(GameObject* child) {
        child->Init(resourceManager);
        childs.push_back(child);
    }
}
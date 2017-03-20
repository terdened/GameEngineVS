//
// Created by terde on 15.02.2017.
//

#include "stdafx.h"
#include "Scene.h"
namespace GameEngine {
    void Scene::Draw() {
        vector<shared_ptr<GameObject>>::iterator gameObjectIter;
		sort(childs.begin(), childs.end(), 
			[](const shared_ptr<GameObject> &lhs, const shared_ptr<GameObject> &rhs) {
				return lhs->Depth() < rhs->Depth();
		});

        for (gameObjectIter = childs.begin(); gameObjectIter != childs.end(); gameObjectIter++)
            (*gameObjectIter)->Draw(TransformData());
    }

    void Scene::Update() {
		vector<shared_ptr<GameObject>>::iterator gameObjectIter;
        for (gameObjectIter = childs.begin(); gameObjectIter != childs.end(); gameObjectIter++)
            (*gameObjectIter)->Update();
    }

    void Scene::AddChild(shared_ptr<GameObject> child) {
        child->Init(resourceManager);
        childs.push_back(child);
    }
}
//
// Created by terde on 15.02.2017.
//

#include "stdafx.h"
#include "Scene.h"
namespace gameengine {
    void Scene::Draw() {
        vector<shared_ptr<GameObject>>::iterator game_objectIter;
		sort(childs.begin(), childs.end(), 
			[](const shared_ptr<GameObject> &lhs, const shared_ptr<GameObject> &rhs) {
				return lhs->Depth() < rhs->Depth();
		});

        for (game_objectIter = childs.begin(); game_objectIter != childs.end(); game_objectIter++)
            (*game_objectIter)->Draw(TransformData());
    }

    void Scene::Update() {
		vector<shared_ptr<GameObject>>::iterator game_objectIter;
        for (game_objectIter = childs.begin(); game_objectIter != childs.end(); game_objectIter++)
            (*game_objectIter)->Update();
    }

    void Scene::AddChild(shared_ptr<GameObject> child) {
        child->Init(resource_manager);
        childs.push_back(child);
    }
}
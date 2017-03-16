//
// Created by terde on 15.02.2017.
//

#ifndef GAME_MAINSCENE_H
#define GAME_MAINSCENE_H

#include "Scene.h"

using  namespace GameEngine;

class MainScene : public Scene {

public:
    MainScene(sf::RenderWindow& app): Scene(app)
            { }

    ~MainScene() {
        resourceManager->EmptyList();
    }

    void Update();
    void Init() override;
};


#endif //GAME_MAINSCENE_H

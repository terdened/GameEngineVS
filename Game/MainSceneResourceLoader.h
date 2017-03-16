//
// Created by terde on 22.02.2017.
//

#ifndef GAME_MAINSCENERESOURCELOADER_H
#define GAME_MAINSCENERESOURCELOADER_H

#include "ResourceLoader.h"

using namespace GameEngine;

class MainSceneResourceLoader: public ResourceLoader {
public:
    MainSceneResourceLoader(ResourceManager* resourceManager): ResourceLoader(resourceManager)
        { }
    void Load() override;
};


#endif //GAME_MAINSCENERESOURCELOADER_H

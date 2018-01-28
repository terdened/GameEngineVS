//
// Created by terde on 22.02.2017.
//

#ifndef GAME_MAINSCENERESOURCELOADER_H
#define GAME_MAINSCENERESOURCELOADER_H

#include "ResourceLoader.h"

using namespace gameengine;

class MainSceneResourceLoader: public ResourceLoader {
public:
    MainSceneResourceLoader(ResourceManager* resource_manager): ResourceLoader(resource_manager)
        { }
    void Load() override;
};


#endif //GAME_MAINSCENERESOURCELOADER_H

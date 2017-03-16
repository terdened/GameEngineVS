//
// Created by terde on 22.02.2017.
//

#ifndef GAME_RESOURCELOADER_H
#define GAME_RESOURCELOADER_H

#include "ResourceManager.h"

namespace GameEngine {
    class ResourceLoader {
    protected:
        ResourceManager* resourceManager;
    public:
        ResourceLoader(ResourceManager* resourceManager): resourceManager(resourceManager)
            { }

        ~ResourceLoader() {
            delete resourceManager;
        }
        virtual void Load() = 0;
    };
}



#endif //GAME_RESOURCELOADER_H

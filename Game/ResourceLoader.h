//
// Created by terde on 22.02.2017.
//

#ifndef GAME_RESOURCELOADER_H
#define GAME_RESOURCELOADER_H

#include "ResourceManager.h"

namespace gameengine {
    class ResourceLoader {
    protected:
        ResourceManager* resource_manager;
    public:
        ResourceLoader(ResourceManager* resource_manager): resource_manager(resource_manager)
            { }

        ~ResourceLoader() {
            delete resource_manager;
        }
        virtual void Load() = 0;
    };
}



#endif //GAME_RESOURCELOADER_H

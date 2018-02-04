//
// Created by terde on 10.03.2017.
//

#ifndef GAME_SPRITE_H
#define GAME_SPRITE_H

#include "game-object.h"

namespace gameengine {
    class SpriteGameObject : public GameObject {
    private:
        string resource_name;
        shared_ptr<sf::Sprite> sprite;
    public:
        SpriteGameObject(sf::RenderWindow& app, string resource_name) : GameObject(app), resource_name(resource_name)
            {   }

        void Init(ResourceManager* resource_manager);
    };
}


#endif //GAME_SPRITE_H

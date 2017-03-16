//
// Created by terde on 10.03.2017.
//

#ifndef GAME_SPRITE_H
#define GAME_SPRITE_H

#include "GameObject.h"

namespace GameEngine {
    class SpriteGameObject : public GameObject {
    private:
        string resourceName;
        shared_ptr<sf::Sprite> sprite;
    public:
        SpriteGameObject(sf::RenderWindow& app, string resourceName) : GameObject(app), resourceName(resourceName)
            {   }

        void Init(ResourceManager* resourceManager);
    };
}


#endif //GAME_SPRITE_H

//
// Created by terde on 17.02.2017.
//

#ifndef GAME_FIELD_H
#define GAME_FIELD_H

#include "GameObject.h"

using namespace gameengine;

class Field : public GameObject{
public:
    Field(sf::RenderWindow& app): GameObject(app)
            { }
    void Update();
    void Init(ResourceManager* resource_manager);
};


#endif //GAME_FIELD_H

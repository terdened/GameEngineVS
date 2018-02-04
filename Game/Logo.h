//
// Created by terde on 22.02.2017.
//

#ifndef GAME_LOGO_H
#define GAME_LOGO_H

#include "resource-manager.h"
#include "sprite.h"

using namespace gameengine;

class Logo : public SpriteGameObject{
public:
	Logo(sf::RenderWindow& app, string resource_name) : SpriteGameObject(app, resource_name)
		{	}
    void Update();
	void Init(ResourceManager* resource_manager);
};


#endif //GAME_LOGO_H

//
// Created by terde on 10.03.2017.
//

#include "stdafx.h"
#include "Sprite.h"
#include "TextureResource.h"

namespace GameEngine {
    void SpriteGameObject::Init(ResourceManager* resourceManager) {
        this->resourceManager = resourceManager;
        sprite = std::make_shared<sf::Sprite>();
        auto texture = this->resourceManager->GetElement<TextureResource>(resourceName)->Texture();
        sprite->setTexture(*texture);
        AddShape(sprite);

        auto spriteWidth = sprite->getGlobalBounds().width;
        auto spriteHeight = sprite->getGlobalBounds().height;

        SetPivotPoint(sf::Vector2f(spriteWidth/2, spriteHeight/2));
    }
}
//
// Created by terde on 22.02.2017.
//

#ifndef GAME_RECTANGULARSILHOUETTE_H
#define GAME_RECTANGULARSILHOUETTE_H


#include "Silhouette.h"

namespace GameEngine{
    class RectangularSilhouette: public Silhouette {
    protected:
        float width;
        float height;
    public:
        RectangularSilhouette(GameObject* gameObject, float width, float height): Silhouette(gameObject), width(width), height(height)
        {}

        bool IsMouseOn(sf::RenderWindow& renderWindow) override;
    };
}


#endif //GAME_RECTANGULARSILHOUETTE_H

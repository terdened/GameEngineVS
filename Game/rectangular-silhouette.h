//
// Created by terde on 22.02.2017.
//

#ifndef GAME_RECTANGULARSILHOUETTE_H
#define GAME_RECTANGULARSILHOUETTE_H


#include "silhouette.h"

namespace gameengine{
    class RectangularSilhouette: public Silhouette {
    protected:
        float width;
        float height;
    public:
        RectangularSilhouette(GameObject* game_object, float width, float height): Silhouette(game_object), width(width), height(height)
        {}

        bool IsMouseOn(sf::RenderWindow& render_window) override;
    };
}


#endif //GAME_RECTANGULARSILHOUETTE_H

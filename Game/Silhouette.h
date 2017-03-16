//
// Created by terde on 22.02.2017.
//

#ifndef GAME_SILHOUETTE_H
#define GAME_SILHOUETTE_H


#include <SFML/Graphics/RenderWindow.hpp>

namespace GameEngine {
    class GameObject;
    class Silhouette {
    protected:
        GameObject* gameObject = nullptr;
    public:
        Silhouette(GameObject* gameObject): gameObject(gameObject)
        {}

        virtual bool IsMouseOn(sf::RenderWindow& renderWindow) = 0;
    };


}


#endif //GAME_SILHOUETTE_H

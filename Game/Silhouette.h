//
// Created by terde on 22.02.2017.
//

#ifndef GAME_SILHOUETTE_H
#define GAME_SILHOUETTE_H


#include <SFML/Graphics/RenderWindow.hpp>

namespace gameengine {
    class GameObject;
    class Silhouette {
    protected:
        GameObject* game_object = nullptr;
    public:
        Silhouette(GameObject* game_object): 
			game_object(game_object){}

        virtual bool IsMouseOn(sf::RenderWindow& render_window) = 0;
    };
}


#endif //GAME_SILHOUETTE_H

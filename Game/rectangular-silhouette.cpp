//
// Created by terde on 22.02.2017.
//

#include "stdafx.h"
#include <SFML/Window/Mouse.hpp>
#include "rectangular-silhouette.h"
#include "game-object.h"

namespace gameengine {
    bool RectangularSilhouette::IsMouseOn(sf::RenderWindow& render_window) {
        float mouse_x = sf::Mouse::getPosition(render_window).x;
        float mouse_y = sf::Mouse::getPosition(render_window).y;

        return mouse_x >= game_object->GlobalX() 
			   && mouse_x <= game_object->GlobalX() + width
               && mouse_y >= game_object->GlobalY() 
			   && mouse_y <= game_object->GlobalY() + height;
    }
}

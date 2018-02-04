#pragma once

#include "stdafx.h"
#include <SFML/Graphics.hpp>

namespace gameengine {
	struct TransformData {
		sf::Vector2f position;
		sf::Vector2f scale;
		float rotation;

		TransformData() : 
			position(sf::Vector2f(0, 0)), 
			scale(sf::Vector2f(1, 1)),
			rotation(0) { }
	};
}
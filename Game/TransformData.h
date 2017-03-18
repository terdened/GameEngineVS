#pragma once

#include "stdafx.h"
#include <SFML/Graphics.hpp>

namespace GameEngine {
	struct TransformData {
		sf::Vector2f Position;
		sf::Vector2f Scale;
		float Rotation;

		TransformData() : Position(sf::Vector2f(0, 0)), Scale(sf::Vector2f(1, 1)), Rotation(0)
			{	}
	};
}
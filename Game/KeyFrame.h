#pragma once


#include "stdafx.h"
#include <SFML/Graphics.hpp>

namespace GameEngine {
	struct KeyFrame {
		int FrameNumber;
		sf::Transform Transform;
		float Rotation;
		sf::Vector2f Scale;
		sf::Vector2f Position;
	};
}
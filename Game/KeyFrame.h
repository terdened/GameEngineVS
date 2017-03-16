#pragma once


#include "stdafx.h"
#include <SFML/Graphics.hpp>

namespace GameEngine {
	class KeyFrame {
	public:
		int FrameNumber;
		sf::Transform Transform;
	};
}
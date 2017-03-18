#pragma once


#include "stdafx.h"
#include "TransformData.h"
#include <SFML/Graphics.hpp>

namespace GameEngine {
	struct KeyFrame {
		int FrameNumber;
		TransformData TransformData;
	};
}
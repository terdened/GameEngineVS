#pragma once


#include "stdafx.h"
#include "TransformData.h"
#include <SFML/Graphics.hpp>

namespace gameengine {
	enum KeyFrameType {
		Static, 
		TransformAnimation
	};

	struct KeyFrame {
		int FrameNumber;
		TransformData TransformData;
		KeyFrameType Type;
	};
}
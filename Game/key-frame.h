#pragma once


#include "stdafx.h"
#include "transform-data.h"
#include <SFML/Graphics.hpp>

namespace gameengine {
	enum KeyFrameType {
		kStatic, 
		kTransformAnimation
	};

	struct KeyFrame {
		int frame_number;
		TransformData transform_data;
		KeyFrameType type;
	};
}
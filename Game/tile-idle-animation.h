#pragma once
#include "stdafx.h"
#include "animation.h"

using  namespace gameengine;

class TileIdleAnimation : public Animation {
public:
	TileIdleAnimation() : Animation() {
		repeat = false;
		duration = 1;
		current_frame = 0;

		auto key_frame_1 = KeyFrame();
		key_frame_1.frame_number = 0;
		key_frame_1.transform_data.position = sf::Vector2f(0, 0);
		key_frame_1.transform_data.rotation = 0;
		key_frame_1.transform_data.scale = sf::Vector2f(1, 1);
		key_frame_1.type = KeyFrameType::kTransformAnimation;
		key_frames.push_back(key_frame_1);
	}
};
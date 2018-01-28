#pragma once
#pragma once

#include "stdafx.h"
#include "Animation.h"

using  namespace gameengine;

class MouseOutTileAnimation : public Animation {
public:
	MouseOutTileAnimation() : Animation() {
		repeat = false;
		duration = 10;
		current_frame = 0;

		auto key_frame_1 = KeyFrame();
		key_frame_1.frame_number = 0;
		key_frame_1.transform_data.position = sf::Vector2f(0, 0);
		key_frame_1.transform_data.rotation = 0;
		key_frame_1.transform_data.scale = sf::Vector2f(1.15, 1.15);
		key_frame_1.type = KeyFrameType::kTransformAnimation;
		key_frames.push_back(key_frame_1);

		auto key_frame_2 = KeyFrame();
		key_frame_2.frame_number = 9;
		key_frame_2.transform_data.position = sf::Vector2f(0, 0);
		key_frame_2.transform_data.rotation = 0;
		key_frame_2.transform_data.scale = sf::Vector2f(1, 1);
		key_frame_2.type = KeyFrameType::kTransformAnimation;
		key_frames.push_back(key_frame_2);
	}
};
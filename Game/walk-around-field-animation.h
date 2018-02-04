#pragma once

#include "stdafx.h"
#include "animation.h"

using  namespace gameengine;

class WalkAroundFieldAnimation : public Animation {
public:
	WalkAroundFieldAnimation() : Animation() {
		repeat = true;
		duration = 400;
		current_frame = 0;

		auto key_frame_1 = KeyFrame();
		key_frame_1.frame_number = 0;
		key_frame_1.transform_data.position = sf::Vector2f(150, -50);
		key_frame_1.transform_data.rotation = 0;
		key_frame_1.transform_data.scale = sf::Vector2f(1, 1);
		key_frame_1.type = KeyFrameType::kTransformAnimation;
		key_frames.push_back(key_frame_1);

		auto key_frame_2 = KeyFrame();
		key_frame_2.frame_number = 100;
		key_frame_2.transform_data.position = sf::Vector2f(820, -50);
		key_frame_2.transform_data.rotation = 360;
		key_frame_2.transform_data.scale = sf::Vector2f(1, 1);
		key_frame_2.type = KeyFrameType::kTransformAnimation;
		key_frames.push_back(key_frame_2);

		auto key_frame_3 = KeyFrame();
		key_frame_3.frame_number = 200;

		key_frame_3.transform_data.position = sf::Vector2f(820, 620);
		key_frame_3.transform_data.rotation = 720;
		key_frame_3.transform_data.scale = sf::Vector2f(1, 1);
		key_frame_3.type = KeyFrameType::kTransformAnimation;
		key_frames.push_back(key_frame_3);


		auto key_frame_4 = KeyFrame();
		key_frame_4.frame_number = 300;

		key_frame_4.transform_data.position = sf::Vector2f(150, 620);
		key_frame_4.transform_data.rotation = 1080;
		key_frame_4.transform_data.scale = sf::Vector2f(1, 1);
		key_frame_4.type = KeyFrameType::kTransformAnimation;
		key_frames.push_back(key_frame_4);


		auto key_frame_5 = KeyFrame();
		key_frame_5.frame_number = 399;
		key_frame_5.transform_data.position = sf::Vector2f(150, -50);
		key_frame_5.transform_data.rotation = 1439;
		key_frame_5.transform_data.scale = sf::Vector2f(1, 1);
		key_frame_5.type = KeyFrameType::kTransformAnimation;
		key_frames.push_back(key_frame_5);
	}
};
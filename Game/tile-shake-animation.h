#pragma once
#include "animation.h"

namespace gameengine {
	class TileShakeAnimation : public Animation {
	public:
		TileShakeAnimation() : Animation() {
			repeat = true;
			duration = 9;
			current_frame = 0;

			auto key_frame_1 = KeyFrame();
			key_frame_1.frame_number = 0;
			key_frame_1.transform_data.position = sf::Vector2f(0, 0);
			key_frame_1.transform_data.rotation = 0;
			key_frame_1.transform_data.scale = sf::Vector2f(1.15, 1.15);
			key_frame_1.type = KeyFrameType::kTransformAnimation;
			key_frames.push_back(key_frame_1);

			auto key_frame_2 = KeyFrame();
			key_frame_2.frame_number = 2;
			key_frame_2.transform_data.position = sf::Vector2f(0, 0);
			key_frame_2.transform_data.rotation = -3;
			key_frame_2.transform_data.scale = sf::Vector2f(1.15, 1.15);
			key_frame_2.type = KeyFrameType::kTransformAnimation;
			key_frames.push_back(key_frame_2);

			auto key_frame_3 = KeyFrame();
			key_frame_3.frame_number = 6;
			key_frame_3.transform_data.position = sf::Vector2f(0, 0);
			key_frame_3.transform_data.rotation = 3;
			key_frame_3.transform_data.scale = sf::Vector2f(1.15, 1.15);
			key_frame_3.type = KeyFrameType::kTransformAnimation;
			key_frames.push_back(key_frame_3);

			auto key_frame_4 = KeyFrame();
			key_frame_4.frame_number = 8;
			key_frame_4.transform_data.position = sf::Vector2f(0, 0);
			key_frame_4.transform_data.rotation = 0;
			key_frame_4.transform_data.scale = sf::Vector2f(1.15, 1.15);
			key_frame_4.type = KeyFrameType::kTransformAnimation;
			key_frames.push_back(key_frame_4);
		}
	};
}
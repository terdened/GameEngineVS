#pragma once
#include "Animation.h"

namespace GameEngine {
	class TileShakeAnimation : public Animation {
	public:
		TileShakeAnimation() : Animation() {
			IsRepeat = true;
			Duration = 9;
			CurrentFrame = 0;

			auto KeyFrame1 = KeyFrame();
			KeyFrame1.FrameNumber = 0;
			KeyFrame1.TransformData.Position = sf::Vector2f(0, 0);
			KeyFrame1.TransformData.Rotation = 0;
			KeyFrame1.TransformData.Scale = sf::Vector2f(1.15, 1.15);
			KeyFrame1.Type = KeyFrameType::TransformAnimation;
			KeyFrames.push_back(KeyFrame1);

			auto KeyFrame2 = KeyFrame();
			KeyFrame2.FrameNumber = 2;
			KeyFrame2.TransformData.Position = sf::Vector2f(0, 0);
			KeyFrame2.TransformData.Rotation = -3;
			KeyFrame2.TransformData.Scale = sf::Vector2f(1.15, 1.15);
			KeyFrame2.Type = KeyFrameType::TransformAnimation;
			KeyFrames.push_back(KeyFrame2);

			auto KeyFrame3 = KeyFrame();
			KeyFrame3.FrameNumber = 6;
			KeyFrame3.TransformData.Position = sf::Vector2f(0, 0);
			KeyFrame3.TransformData.Rotation = 3;
			KeyFrame3.TransformData.Scale = sf::Vector2f(1.15, 1.15);
			KeyFrame3.Type = KeyFrameType::TransformAnimation;
			KeyFrames.push_back(KeyFrame3);

			auto KeyFrame4 = KeyFrame();
			KeyFrame4.FrameNumber = 8;
			KeyFrame4.TransformData.Position = sf::Vector2f(0, 0);
			KeyFrame4.TransformData.Rotation = 0;
			KeyFrame4.TransformData.Scale = sf::Vector2f(1.15, 1.15);
			KeyFrame4.Type = KeyFrameType::TransformAnimation;
			KeyFrames.push_back(KeyFrame4);
		}
	};
}
#pragma once

#include "stdafx.h"
#include "Animation.h"

using  namespace GameEngine;

class WalkAroundFieldAnimation : public Animation {
public:
	WalkAroundFieldAnimation() : Animation() {
		IsRepeat = true;
		Duration = 400;
		CurrentFrame = 0;

		auto KeyFrame1 = KeyFrame();
		KeyFrame1.FrameNumber = 0;
		KeyFrame1.TransformData.Position = sf::Vector2f(150, -50);
		KeyFrame1.TransformData.Rotation = 0;
		KeyFrame1.TransformData.Scale = sf::Vector2f(1, 1);
		KeyFrame1.Type = KeyFrameType::TransformAnimation;
		KeyFrames.push_back(KeyFrame1);

		auto KeyFrame2 = KeyFrame();
		KeyFrame2.FrameNumber = 100;
		KeyFrame2.TransformData.Position = sf::Vector2f(820, -50);
		KeyFrame2.TransformData.Rotation = 360;
		KeyFrame2.TransformData.Scale = sf::Vector2f(1, 1);
		KeyFrame2.Type = KeyFrameType::TransformAnimation;
		KeyFrames.push_back(KeyFrame2);

		auto KeyFrame3 = KeyFrame();
		KeyFrame3.FrameNumber = 200;

		KeyFrame3.TransformData.Position = sf::Vector2f(820, 620);
		KeyFrame3.TransformData.Rotation = 720;
		KeyFrame3.TransformData.Scale = sf::Vector2f(1, 1);
		KeyFrame3.Type = KeyFrameType::TransformAnimation;
		KeyFrames.push_back(KeyFrame3);


		auto KeyFrame4 = KeyFrame();
		KeyFrame4.FrameNumber = 300;

		KeyFrame4.TransformData.Position = sf::Vector2f(150, 620);
		KeyFrame4.TransformData.Rotation = 1080;
		KeyFrame4.TransformData.Scale = sf::Vector2f(1, 1);
		KeyFrame4.Type = KeyFrameType::TransformAnimation;
		KeyFrames.push_back(KeyFrame4);


		auto KeyFrame5 = KeyFrame();
		KeyFrame5.FrameNumber = 399;
		KeyFrame5.TransformData.Position = sf::Vector2f(150, -50);
		KeyFrame5.TransformData.Rotation = 1439;
		KeyFrame5.TransformData.Scale = sf::Vector2f(1, 1);
		KeyFrame5.Type = KeyFrameType::TransformAnimation;
		KeyFrames.push_back(KeyFrame5);
	}
};
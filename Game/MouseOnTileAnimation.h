#pragma once
#pragma once

#include "stdafx.h"
#include "Animation.h"

using  namespace GameEngine;

class MouseOnTileAnimation : public Animation {
public:
	MouseOnTileAnimation() : Animation() {
		IsRepeat = false;
		Duration = 10;
		CurrentFrame = 0;

		auto KeyFrame1 = KeyFrame();
		KeyFrame1.FrameNumber = 0;
		KeyFrame1.TransformData.Position = sf::Vector2f(0, 0);
		KeyFrame1.TransformData.Rotation = 0;
		KeyFrame1.TransformData.Scale = sf::Vector2f(1, 1);
		KeyFrames.push_back(KeyFrame1);

		auto KeyFrame2 = KeyFrame();
		KeyFrame2.FrameNumber = 9;
		KeyFrame2.TransformData.Position = sf::Vector2f(0, 0);
		KeyFrame2.TransformData.Rotation = 0;
		KeyFrame2.TransformData.Scale = sf::Vector2f(1.1, 1.1);
		KeyFrames.push_back(KeyFrame2);
	}
};
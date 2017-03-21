#pragma once
#include "stdafx.h"
#include "Animation.h"

using  namespace GameEngine;

class TileIdleAnimation : public Animation {
public:
	TileIdleAnimation() : Animation() {
		IsRepeat = false;
		Duration = 1;
		CurrentFrame = 0;

		auto KeyFrame1 = KeyFrame();
		KeyFrame1.FrameNumber = 0;
		KeyFrame1.TransformData.Position = sf::Vector2f(0, 0);
		KeyFrame1.TransformData.Rotation = 0;
		KeyFrame1.TransformData.Scale = sf::Vector2f(1, 1);
		KeyFrame1.Type = KeyFrameType::TransformAnimation;
		KeyFrames.push_back(KeyFrame1);
	}
};
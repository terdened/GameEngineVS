#pragma once

#include "stdafx.h"
#include "KeyFrame.h"
#include <vector>

namespace GameEngine {
	class Animation {
	private:
		sf::Transform CurrentTransform;
		int Duration;
		int CurrentFrame;
		std::vector<KeyFrame> KeyFrames;
		bool IsRepeat;
		KeyFrame GetActiveKeyFrame(int currentFrame);
		KeyFrame GetNextKeyFrame(int currentFrame);
	public:
		Animation() {
			IsRepeat = true;
			Duration = 400;
			CurrentFrame = 0;

			auto KeyFrame1 = KeyFrame();
			KeyFrame1.FrameNumber = 0;
			KeyFrame1.Transform = sf::Transform();
			KeyFrames.push_back(KeyFrame1);

			auto KeyFrame2 = KeyFrame();
			KeyFrame2.FrameNumber = 100;
			KeyFrame2.Transform = sf::Transform();
			KeyFrame2.Transform.translate(sf::Vector2f(1000, 0));
			KeyFrame2.Transform.rotate(90);
			KeyFrames.push_back(KeyFrame2);

			auto KeyFrame3 = KeyFrame();
			KeyFrame3.FrameNumber = 200;
			KeyFrame3.Transform = sf::Transform();
			KeyFrame3.Transform.translate(sf::Vector2f(1000, 800));
			KeyFrame3.Transform.rotate(180);
			KeyFrames.push_back(KeyFrame3);


			auto KeyFrame4 = KeyFrame();
			KeyFrame4.FrameNumber = 300;
			KeyFrame4.Transform = sf::Transform();
			KeyFrame4.Transform.translate(sf::Vector2f(0, 800));
			KeyFrame4.Transform.rotate(270);
			KeyFrames.push_back(KeyFrame4);


			auto KeyFrame5 = KeyFrame();
			KeyFrame5.FrameNumber = 399;
			KeyFrame5.Transform = sf::Transform();
			KeyFrame5.Transform.translate(sf::Vector2f(0, 0));
			KeyFrames.push_back(KeyFrame5);
		}
		void Update();
		sf::Transform GetCurrentTransform() {
			return CurrentTransform;
		}
	};
}
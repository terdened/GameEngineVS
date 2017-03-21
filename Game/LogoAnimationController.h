#pragma once

#include "AnimationController.h"
#include "WalkAroundFieldAnimation.h"

namespace GameEngine {
	class LogoAnimationController : public AnimationController {
	public:
		LogoAnimationController() {
			auto walkAroundFieldAnimation = std::make_shared<WalkAroundFieldAnimation>();
			CurrentAnimation = walkAroundFieldAnimation;
			CurrentAnimation->Play();
		}
	};
}
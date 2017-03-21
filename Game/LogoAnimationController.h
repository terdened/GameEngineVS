#pragma once

#include "AnimationController.h"
#include "WalkAroundFieldAnimation.h"

namespace GameEngine {
	class LogoAnimationController : public AnimationController {
	public:
		LogoAnimationController() {
			auto walkAroundFieldAnimation = new WalkAroundFieldAnimation();
			CurrentAnimation = walkAroundFieldAnimation;
		}
	};
}
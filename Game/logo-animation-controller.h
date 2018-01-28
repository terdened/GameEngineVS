#pragma once

#include "AnimationController.h"
#include "walk-around-field-animation.h"

namespace gameengine {
	class LogoAnimationController : public AnimationController {
	public:
		LogoAnimationController() {
			auto walk_around_field_animation = std::make_shared<WalkAroundFieldAnimation>();
			current_animation = walk_around_field_animation;
			current_animation->Play();
		}
	};
}
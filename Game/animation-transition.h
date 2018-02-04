#pragma once

#include "animation.h"
#include <memory>

using namespace std;

namespace gameengine {
	enum AnimaitonTransitionType {
		kWaitUntilAnimationEnd,
		kImmediately
	};

	class AnimationTransition 
	{
	public:
		AnimationTransition (AnimaitonTransitionType type, shared_ptr<Animation> next_animaiton)
			:  type(type), 
			   next_animaiton(next_animaiton) {}

		shared_ptr<Animation> GetNextAnimation() {
			return next_animaiton;
		}

		bool(*Condition)(map<string, string> params);

		bool IsActive(map<string, string> params, bool IsAnimationEnded) {
			return ((IsAnimationEnded && type == kWaitUntilAnimationEnd) || type == kImmediately) && (Condition(params));
		}
	private:
		AnimaitonTransitionType type;
		shared_ptr<Animation> next_animaiton;
	};
}
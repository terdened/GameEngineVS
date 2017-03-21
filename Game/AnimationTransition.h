#pragma once

#include "Animation.h"

namespace GameEngine {
	enum AnimaitonTransitionType {
		WaitUntilAnimationEnd,
		Immediately
	};

	class AnimationTransition 
	{
	public:
		AnimationTransition (AnimaitonTransitionType type, Animation* nextAnimaiton): Type(type), NextAnimaiton(nextAnimaiton)
			{	}

		bool(*Condition)(std::map<std::string, std::string> params);
		Animation* GetNextAnimation() {
			return NextAnimaiton;
		}
		bool IsActive(std::map<std::string, std::string> params, bool IsAnimationEnded) {
			return ((IsAnimationEnded && Type == WaitUntilAnimationEnd) || Type == Immediately) && (Condition(params));
		}
	private:
		AnimaitonTransitionType Type;
		Animation* NextAnimaiton;
	};
}
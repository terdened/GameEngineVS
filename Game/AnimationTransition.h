#pragma once

#include "Animation.h"
#include <memory>

using namespace std;

namespace gameengine {
	enum AnimaitonTransitionType {
		WaitUntilAnimationEnd,
		Immediately
	};

	class AnimationTransition 
	{
	public:
		AnimationTransition (AnimaitonTransitionType type, shared_ptr<Animation> nextAnimaiton): Type(type), NextAnimaiton(nextAnimaiton)
			{	}

		shared_ptr<Animation> GetNextAnimation() {
			return NextAnimaiton;
		}

		bool(*Condition)(map<string, string> params);

		bool IsActive(map<string, string> params, bool IsAnimationEnded) {
			return ((IsAnimationEnded && Type == WaitUntilAnimationEnd) || Type == Immediately) && (Condition(params));
		}
	private:
		AnimaitonTransitionType Type;
		shared_ptr<Animation> NextAnimaiton;
	};
}
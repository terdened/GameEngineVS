#pragma once

#include "Animation.h"
#include "AnimationTransition.h"
#include <map>
#include <string>

using namespace std;

namespace GameEngine {

	class AnimationController {
	public: 
		AnimationController()
			{	}
		void Update();

		shared_ptr<Animation> GetCurrentAnimation() {
			return CurrentAnimation;
		}
		map<string, string> Params;
		void SetParamValue(string key, string value);

	protected:
		shared_ptr<Animation> CurrentAnimation;
		multimap<shared_ptr<Animation>, shared_ptr<AnimationTransition>> AnimationMap;
	private:
		shared_ptr<Animation> GetNextAnimation();
	};
}
#pragma once

#include "Animation.h"
#include "AnimationTransition.h"
#include <map>
#include <string>

using namespace std;

namespace gameengine {

	class AnimationController {
	public: 
		AnimationController()
			{	}
		void Update();

		shared_ptr<Animation> GetCurrentAnimation() {
			return current_animation;
		}
		map<string, string> params;
		void SetParamValue(string key, string value);

	protected:
		shared_ptr<Animation> current_animation;
		multimap<shared_ptr<Animation>, shared_ptr<AnimationTransition>> animation_map;
	private:
		shared_ptr<Animation> GetNextAnimation();
	};
}
#pragma once

#include "Animation.h"
#include "AnimationTransition.h"
#include <map>
#include <string>

namespace GameEngine {

	class AnimationController {
	public: 
		AnimationController()
			{	}
		void Update();

		Animation* GetCurrentAnimation() {
			return CurrentAnimation;
		}
		std::map<std::string, std::string> Params;
		void SetParamValue(std::string key, std::string value);

	protected:
		Animation* CurrentAnimation;
		std::multimap<Animation*, AnimationTransition> AnimationMap;
	private:
		Animation* GetNextAnimation();
	};
}
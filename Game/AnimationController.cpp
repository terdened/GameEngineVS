#pragma once

#include "stdafx.h"
#include "AnimationController.h" 
#include <string>

namespace GameEngine {

	void AnimationController::Update() {
		Animation* nextAnimation = GetNextAnimation();

		if (nextAnimation != nullptr) {
			CurrentAnimation = nextAnimation;
			CurrentAnimation->Play();
		}

		if (CurrentAnimation != nullptr)
			CurrentAnimation->Update();
	}


	void AnimationController::SetParamValue(std::string key, std::string value) {
		std::map<std::string, std::string>::iterator it = Params.find(key);
		if (it != Params.end())
			it->second = value;
		else
			Params.insert(std::make_pair(key, value));
	}

	Animation* AnimationController::GetNextAnimation() {
		std::pair <std::multimap<Animation*, AnimationTransition>::iterator, std::multimap<Animation*, AnimationTransition>::iterator> ret;
		ret = AnimationMap.equal_range(CurrentAnimation);
		auto IsAnimationEnded = CurrentAnimation->State() == AnimationState::Ended;

		for (auto it = ret.first; it != ret.second; ++it) {
			if (it->second.IsActive(Params, IsAnimationEnded))
				return it->second.GetNextAnimation();
		}

		return nullptr;
	}
}
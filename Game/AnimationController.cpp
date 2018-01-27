#pragma once

#include "stdafx.h"
#include "AnimationController.h" 
#include <string>

namespace gameengine {

	void AnimationController::Update() {
		auto nextAnimation = GetNextAnimation();

		if (nextAnimation != nullptr) {
			CurrentAnimation = nextAnimation;
			CurrentAnimation->Play();
		}

		if (CurrentAnimation != nullptr)
			CurrentAnimation->Update();
	}


	void AnimationController::SetParamValue(string key, string value) {
		auto it = Params.find(key);
		if (it != Params.end())
			it->second = value;
		else
			Params.insert(make_pair(key, value));
	}

	shared_ptr<Animation> AnimationController::GetNextAnimation() {
		pair <multimap<shared_ptr<Animation>, shared_ptr<AnimationTransition>>::iterator, multimap<shared_ptr<Animation>, shared_ptr<AnimationTransition>>::iterator> ret;
		ret = AnimationMap.equal_range(CurrentAnimation);
		auto IsAnimationEnded = CurrentAnimation->State() == AnimationState::Ended;

		for (auto it = ret.first; it != ret.second; ++it) {
			if (it->second->IsActive(Params, IsAnimationEnded))
				return it->second->GetNextAnimation();
		}

		return nullptr;
	}
}
#pragma once

#include "stdafx.h"
#include "animation-controller.h" 
#include <string>

namespace gameengine {
	void AnimationController::Update() {
		auto next_animation = GetNextAnimation();

		if (next_animation != nullptr) {
			current_animation = next_animation;
			current_animation->Play();
		}

		if (current_animation != nullptr)
			current_animation->Update();
	}

	void AnimationController::SetParamValue(string key, string value) {
		auto it = params.find(key);
		if (it != params.end())
			it->second = value;
		else
			params.insert(make_pair(key, value));
	}

	shared_ptr<Animation> AnimationController::GetNextAnimation() {
		pair <multimap<shared_ptr<Animation>, shared_ptr<AnimationTransition>>::iterator, multimap<shared_ptr<Animation>, shared_ptr<AnimationTransition>>::iterator> ret;
		ret = animation_map.equal_range(current_animation);
		bool animation_ended = current_animation->State() == AnimationState::kEnded;

		for (auto it = ret.first; it != ret.second; ++it) {
			if (it->second->IsActive(params, animation_ended))
				return it->second->GetNextAnimation();
		}

		return nullptr;
	}
}
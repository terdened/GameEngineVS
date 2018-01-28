#pragma once
#include "AnimationController.h"
#include "mouse-on-tile-animation.h"
#include "mouse-out-tile-animation.h"
#include "tile-shake-animation.h"
#include "tile-idle-animation.h"

using namespace std;

namespace gameengine {
	class TileAnimationController: public AnimationController {
	public:
		TileAnimationController() {
			auto tile_idle_animation = make_shared<TileIdleAnimation>();
			auto mouse_on_tile_animation = make_shared<MouseOnTileAnimation>();
			auto shake_tile_animation = make_shared<TileShakeAnimation>();
			auto mouse_out_tile_animation = make_shared<MouseOutTileAnimation>();

			params.insert(pair<string, string>("State", "0"));
			current_animation = tile_idle_animation;
			current_animation->Play();

			auto idle_to_mosue_on = make_shared<AnimationTransition>(AnimaitonTransitionType::kImmediately, mouse_on_tile_animation);
			idle_to_mosue_on->Condition = [](map<string, string> params) { return params["State"] == "1"; };
			animation_map.insert(pair<shared_ptr<Animation>, shared_ptr<AnimationTransition>>(tile_idle_animation, idle_to_mosue_on));

			auto mosue_on_to_shake = make_shared<AnimationTransition>(AnimaitonTransitionType::kWaitUntilAnimationEnd, shake_tile_animation);
			mosue_on_to_shake->Condition = [](map<string, string> params) { return params["State"] == "1"; };
			animation_map.insert(pair<shared_ptr<Animation>, shared_ptr<AnimationTransition>>(mouse_on_tile_animation, mosue_on_to_shake));
			
			auto mosue_on_to_mouse_out = make_shared<AnimationTransition>(AnimaitonTransitionType::kWaitUntilAnimationEnd, mouse_out_tile_animation);
			mosue_on_to_mouse_out->Condition = [](map<string, string> params) { return params["State"] == "0"; };
			animation_map.insert(pair<shared_ptr<Animation>, shared_ptr<AnimationTransition>>(mouse_on_tile_animation, mosue_on_to_mouse_out));

			auto shake_to_mouse_out = make_shared<AnimationTransition>(AnimaitonTransitionType::kWaitUntilAnimationEnd, mouse_out_tile_animation);
			shake_to_mouse_out->Condition = [](map<string, string> params) { return params["State"] == "0"; };
			animation_map.insert(pair<shared_ptr<Animation>, shared_ptr<AnimationTransition>>(shake_tile_animation, mosue_on_to_mouse_out));

			auto mouse_out_to_idle = make_shared<AnimationTransition>(AnimaitonTransitionType::kWaitUntilAnimationEnd, tile_idle_animation);
			mouse_out_to_idle->Condition = [](map<string, string> params) { return true; };
			animation_map.insert(pair<shared_ptr<Animation>, shared_ptr<AnimationTransition>>(mouse_out_tile_animation, mouse_out_to_idle));
		}
	};
}
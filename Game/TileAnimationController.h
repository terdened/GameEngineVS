#pragma once
#include "AnimationController.h"
#include "MouseOnTileAnimation.h"
#include "TileShakeAnimation.h"
#include "MouseOutTileAnimation.h"
#include "TileIdleAnimation.h"

namespace GameEngine {
	class TileAnimationController: public AnimationController {
	public:
		TileAnimationController() {
			auto tileIdleAnimation = new TileIdleAnimation();
			auto mouseOnTileAnimation = new MouseOnTileAnimation();
			auto shakeTileAnimation = new TileShakeAnimation();
			auto mouseOutTileAnimation = new MouseOutTileAnimation();

			Params.insert(std::pair<std::string, std::string>("State", "0"));
			CurrentAnimation = tileIdleAnimation;

			auto idleToMosueOn = AnimationTransition(AnimaitonTransitionType::Immediately, mouseOnTileAnimation);
			idleToMosueOn.Condition = [](std::map<std::string, std::string> Params) { return Params["State"] == "1"; };
			AnimationMap.insert(std::pair<Animation*, AnimationTransition>(tileIdleAnimation, idleToMosueOn));

			auto mosueOnToShake = AnimationTransition(AnimaitonTransitionType::WaitUntilAnimationEnd, shakeTileAnimation);
			mosueOnToShake.Condition = [](std::map<std::string, std::string> Params) { return Params["State"] == "1"; };
			AnimationMap.insert(std::pair<Animation*, AnimationTransition>(mouseOnTileAnimation, mosueOnToShake));
			
			auto mosueOnToMouseOut = AnimationTransition(AnimaitonTransitionType::WaitUntilAnimationEnd, mouseOutTileAnimation);
			mosueOnToMouseOut.Condition = [](std::map<std::string, std::string> Params) { return Params["State"] == "0"; };
			AnimationMap.insert(std::pair<Animation*, AnimationTransition>(mouseOnTileAnimation, mosueOnToMouseOut));

			auto shakeToMouseOut = AnimationTransition(AnimaitonTransitionType::WaitUntilAnimationEnd, mouseOutTileAnimation);
			shakeToMouseOut.Condition = [](std::map<std::string, std::string> Params) { return Params["State"] == "0"; };
			AnimationMap.insert(std::pair<Animation*, AnimationTransition>(shakeTileAnimation, mosueOnToMouseOut));

			auto mouseOutToIdle = AnimationTransition(AnimaitonTransitionType::WaitUntilAnimationEnd, tileIdleAnimation);
			mouseOutToIdle.Condition = [](std::map<std::string, std::string> Params) { return true; };
			AnimationMap.insert(std::pair<Animation*, AnimationTransition>(mouseOutTileAnimation, mouseOutToIdle));
		}
	};
}
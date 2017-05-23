#pragma once
#include "AnimationController.h"
#include "MouseOnTileAnimation.h"
#include "TileShakeAnimation.h"
#include "MouseOutTileAnimation.h"
#include "TileIdleAnimation.h"

using namespace std;

namespace GameEngine {
	class TileAnimationController: public AnimationController {
	public:
		TileAnimationController() {
			auto tileIdleAnimation = make_shared<TileIdleAnimation>();
			auto mouseOnTileAnimation = make_shared<MouseOnTileAnimation>();
			//auto shakeTileAnimation = make_shared<TileShakeAnimation>();
			auto mouseOutTileAnimation = make_shared<MouseOutTileAnimation>();

			Params.insert(pair<string, string>("State", "0"));
			CurrentAnimation = tileIdleAnimation;
			CurrentAnimation->Play();

			auto idleToMosueOn = make_shared<AnimationTransition>(AnimaitonTransitionType::Immediately, mouseOnTileAnimation);
			idleToMosueOn->Condition = [](map<string, string> Params) { return Params["State"] == "1"; };
			AnimationMap.insert(pair<shared_ptr<Animation>, shared_ptr<AnimationTransition>>(tileIdleAnimation, idleToMosueOn));

			/*auto mosueOnToShake = make_shared<AnimationTransition>(AnimaitonTransitionType::WaitUntilAnimationEnd, shakeTileAnimation);
			mosueOnToShake->Condition = [](map<string, string> Params) { return Params["State"] == "1"; };
			AnimationMap.insert(pair<shared_ptr<Animation>, shared_ptr<AnimationTransition>>(mouseOnTileAnimation, mosueOnToShake));*/
			
			auto mosueOnToMouseOut = make_shared<AnimationTransition>(AnimaitonTransitionType::WaitUntilAnimationEnd, mouseOutTileAnimation);
			mosueOnToMouseOut->Condition = [](map<string, string> Params) { return Params["State"] == "0"; };
			AnimationMap.insert(pair<shared_ptr<Animation>, shared_ptr<AnimationTransition>>(mouseOnTileAnimation, mosueOnToMouseOut));

			/*auto shakeToMouseOut = make_shared<AnimationTransition>(AnimaitonTransitionType::WaitUntilAnimationEnd, mouseOutTileAnimation);
			shakeToMouseOut->Condition = [](map<string, string> Params) { return Params["State"] == "0"; };
			AnimationMap.insert(pair<shared_ptr<Animation>, shared_ptr<AnimationTransition>>(shakeTileAnimation, mosueOnToMouseOut));*/

			auto mouseOutToIdle = make_shared<AnimationTransition>(AnimaitonTransitionType::WaitUntilAnimationEnd, tileIdleAnimation);
			mouseOutToIdle->Condition = [](map<string, string> Params) { return true; };
			AnimationMap.insert(pair<shared_ptr<Animation>, shared_ptr<AnimationTransition>>(mouseOutTileAnimation, mouseOutToIdle));
		}
	};
}
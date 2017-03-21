#pragma once

#include "stdafx.h"
#include "KeyFrame.h"
#include <vector>

namespace GameEngine {
	enum AnimationState {
		Played,
		Paused,
		Stoped,
		Ended
	};

	class Animation {
	private:
		KeyFrame CurrentTransform;
		KeyFrame GetActiveKeyFrame(int currentFrame);
		KeyFrame GetNextKeyFrame(int currentFrame);
	protected:
		int Duration;
		int CurrentFrame;
		std::vector<KeyFrame> KeyFrames;
		bool IsRepeat;
		AnimationState state;
	public:
		Animation() {
			IsRepeat = true;
			Duration = 0;
			CurrentFrame = 0;
		}

		void Update();
		void Play();
		void Stop();
		void Pause();

		KeyFrame GetCurrentTransform() {
			return CurrentTransform;
		}

		AnimationState State() {
			return state;
		}
	};
}
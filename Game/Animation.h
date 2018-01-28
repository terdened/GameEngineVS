#pragma once

#include "stdafx.h"
#include "KeyFrame.h"
#include <vector>

namespace gameengine {
	enum AnimationState {
		kPlayed,
		kPaused,
		kStoped,
		kEnded
	};

	class Animation {
	private:
		KeyFrame current_transform;
		KeyFrame GetActiveKeyFrame(int current_frame);
		KeyFrame get_next_key_frame(int current_frame);
	protected:
		int duration;
		int current_frame;
		std::vector<KeyFrame> key_frames;
		bool repeat;
		AnimationState state;
	public:
		Animation() {
			repeat = true;
			duration = 0;
			current_frame = 0;
		}

		void Update();
		void Play();
		void Stop();
		void Pause();

		KeyFrame GetCurrentTransform() {
			return current_transform;
		}

		AnimationState State() {
			return state;
		}
	};
}
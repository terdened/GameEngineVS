#include "stdafx.h"
#include "Animation.h"
#include <algorithm>

using namespace std;

namespace gameengine {

	void Animation::Play() {
		state = AnimationState::kPlayed;
	}

	void Animation::Stop() {
		current_frame = 0;
		state = AnimationState::kStoped;
	}

	void Animation::Pause() {
		state = AnimationState::kPaused;
	}

	void Animation::Update() {
		if ((state != AnimationState::kPlayed && !repeat) 
			|| (state != AnimationState::kPlayed && state != AnimationState::kEnded && repeat))
			return;

		current_frame++;

		if (current_frame >= duration) {
			current_frame = 0;
			state = AnimationState::kEnded;

			return;
		}

		auto active_frame = GetActiveKeyFrame(current_frame);
		
		if (active_frame.type == KeyFrameType::kStatic) {
			current_transform = active_frame;
			return;
		}

		auto next_frame = get_next_key_frame(current_frame);
		
		int current_key_frame_duration = next_frame.frame_number - active_frame.frame_number;
		int current_key_frame_position = current_frame - active_frame.frame_number;

		if (current_key_frame_duration == 0) {
			current_transform = active_frame;
			return;
		}

		auto result_frame = KeyFrame();

		auto delta_position = (next_frame.transform_data.position - active_frame.transform_data.position);
		delta_position.x  = delta_position.x * current_key_frame_position / current_key_frame_duration;
		delta_position.y  = delta_position.y * current_key_frame_position /current_key_frame_duration;

		auto delta_scale = (next_frame.transform_data.scale - active_frame.transform_data.scale);
		delta_scale.x = delta_scale.x * current_key_frame_position / current_key_frame_duration;
		delta_scale.y = delta_scale.y * current_key_frame_position / current_key_frame_duration;

		auto delta_rotation = (next_frame.transform_data.rotation - active_frame.transform_data.rotation) * current_key_frame_position / current_key_frame_duration;

		auto current_frame = KeyFrame();

		current_frame.transform_data.position = active_frame.transform_data.position + delta_position;
		current_frame.transform_data.scale = active_frame.transform_data.scale + delta_scale;
		current_frame.transform_data.rotation = active_frame.transform_data.rotation + delta_rotation;
		
		current_transform = current_frame;
	}

	KeyFrame Animation::GetActiveKeyFrame(int current_frame) {
		auto frame = find_if(key_frames.begin(), key_frames.end(), [&current_frame](KeyFrame kf) { return kf.frame_number == current_frame; });
		while (current_frame > 0 && frame == key_frames.end()) {
			current_frame--;
			frame = find_if(key_frames.begin(), key_frames.end(), [&current_frame](KeyFrame kf) { return kf.frame_number == current_frame; });
		}

		if (frame == key_frames.end())
			throw exception("Can't find KeyFrame");

		return *frame;
	}

	KeyFrame Animation::get_next_key_frame(int current_frame) {
		auto frame = find_if(key_frames.begin(), key_frames.end(), [&current_frame](KeyFrame kf) { return kf.frame_number == current_frame; });
		while (current_frame < duration && frame == key_frames.end()) {
			current_frame++;
			frame = find_if(key_frames.begin(), key_frames.end(), [&current_frame](KeyFrame kf) { return kf.frame_number == current_frame; });
		}

		if (frame == key_frames.end())
			return GetActiveKeyFrame(current_frame);

		return *frame;
	}
}
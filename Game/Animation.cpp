
#include "stdafx.h"
#include "Animation.h"
#include <algorithm>

using namespace std;

namespace GameEngine {

	void Animation::Play() {
		state = AnimationState::Played;
	}

	void Animation::Stop() {
		CurrentFrame = 0;
		state = AnimationState::Stoped;
	}

	void Animation::Pause() {
		state = AnimationState::Paused;
	}

	void Animation::Update() {
		if ((state != AnimationState::Played && !IsRepeat) || (state != AnimationState::Played && state != AnimationState::Ended && IsRepeat))
			return;

		CurrentFrame++;

		if (CurrentFrame >= Duration) {
			CurrentFrame = 0;
			state = AnimationState::Ended;

			return;
		}

		auto activeFrame = GetActiveKeyFrame(CurrentFrame);
		
		if (activeFrame.Type == KeyFrameType::Static) {
			CurrentTransform = activeFrame;
			return;
		}


		auto nextFrame = GetNextKeyFrame(CurrentFrame);
		
		int currentKeyFrameDuration = nextFrame.FrameNumber - activeFrame.FrameNumber;
		int currentKeyFramePosition = CurrentFrame - activeFrame.FrameNumber;

		if (currentKeyFrameDuration == 0) {
			CurrentTransform = activeFrame;
			return;
		}

		auto resultFrame = KeyFrame();

		auto deltaPosition = (nextFrame.TransformData.Position - activeFrame.TransformData.Position);
		deltaPosition.x  = deltaPosition.x * currentKeyFramePosition / currentKeyFrameDuration;
		deltaPosition.y  = deltaPosition.y * currentKeyFramePosition /currentKeyFrameDuration;

		auto deltaScale = (nextFrame.TransformData.Scale - activeFrame.TransformData.Scale);
		deltaScale.x = deltaScale.x * currentKeyFramePosition / currentKeyFrameDuration;
		deltaScale.y = deltaScale.y * currentKeyFramePosition / currentKeyFrameDuration;

		auto deltaRotation = (nextFrame.TransformData.Rotation - activeFrame.TransformData.Rotation) * currentKeyFramePosition / currentKeyFrameDuration;

		auto currentFrame = KeyFrame();

		currentFrame.TransformData.Position = activeFrame.TransformData.Position + deltaPosition;
		currentFrame.TransformData.Scale = activeFrame.TransformData.Scale + deltaScale;
		currentFrame.TransformData.Rotation = activeFrame.TransformData.Rotation + deltaRotation;
		
		CurrentTransform = currentFrame;
	}

	KeyFrame Animation::GetActiveKeyFrame(int currentFrame) {
		auto frame = find_if(KeyFrames.begin(), KeyFrames.end(), [&currentFrame](KeyFrame kf) { return kf.FrameNumber == currentFrame; });
		while (currentFrame > 0 && frame == KeyFrames.end()) {
			currentFrame--;
			frame = find_if(KeyFrames.begin(), KeyFrames.end(), [&currentFrame](KeyFrame kf) { return kf.FrameNumber == currentFrame; });
		}

		if (frame == KeyFrames.end())
			throw exception("Can't find KeyFrame");

		return *frame;
	}

	KeyFrame Animation::GetNextKeyFrame(int currentFrame) {
		auto frame = find_if(KeyFrames.begin(), KeyFrames.end(), [&currentFrame](KeyFrame kf) { return kf.FrameNumber == currentFrame; });
		while (currentFrame < Duration && frame == KeyFrames.end()) {
			currentFrame++;
			frame = find_if(KeyFrames.begin(), KeyFrames.end(), [&currentFrame](KeyFrame kf) { return kf.FrameNumber == currentFrame; });
		}

		if (frame == KeyFrames.end())
			return GetActiveKeyFrame(CurrentFrame);

		return *frame;
	}
}
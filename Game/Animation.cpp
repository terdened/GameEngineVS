
#include "stdafx.h"
#include "Animation.h"
#include <algorithm>

using namespace std;

namespace GameEngine {

	float* AddMatrix(const float* a, const float* b) {
		auto c = new float[16];

		for (int i = 0; i < 16; i++) {
			c[i] = a[i] + b[i];
		}

		return c;
	}

	float* SubMatrix(const float* a, const float* b) {
		auto c = new float[16];

		for (int i = 0; i < 16; i++) {
			c[i] = a[i] - b[i];
		}

		return c;
	}

	float* SubdivideMatrix(const float* a, float b) {
		auto c = new float[16];

		for (int i = 0; i < 16; i++) {
			c[i] = a[i] / b;
		}

		return c;
	}

	float* MultiplyMatrix(const float* a, float b) {
		auto c = new float[16];

		for (int i = 0; i < 16; i++) {
			c[i] = a[i] * b;
		}

		return c;
	}

	sf::Transform GetTransformBasedOnFrame(KeyFrame frame, float pivotX, float pivotY) {
		auto result = sf::Transform();
		result.translate(frame.Position);
		result.scale(frame.Scale);
		result.rotate(frame.Rotation, pivotX, pivotY);
		return result;
	}

	void Animation::Update() {
		CurrentFrame++;

		if (CurrentFrame > Duration) {
			if (IsRepeat)
				CurrentFrame = 1;
			else
				return;
		}

		auto activeFrame = GetActiveKeyFrame(CurrentFrame);
		auto nextFrame = GetNextKeyFrame(CurrentFrame);
		
		int currentKeyFrameDuration = nextFrame.FrameNumber - activeFrame.FrameNumber;
		int currentKeyFramePosition = CurrentFrame - activeFrame.FrameNumber;

		if (currentKeyFrameDuration == 0) {
			CurrentTransform = activeFrame;
			return;
		}

		auto resultFrame = KeyFrame();

		//auto activeFrameMatrix = activeFrame.Transform.getMatrix();
		//auto nextFrameMatrix = nextFrame.Transform.getMatrix();

		auto deltaPosition = (nextFrame.Position - activeFrame.Position);
		deltaPosition.x  = deltaPosition.x * currentKeyFramePosition / currentKeyFrameDuration;
		deltaPosition.y  = deltaPosition.y * currentKeyFramePosition /currentKeyFrameDuration;

		auto deltaScale = (nextFrame.Scale - activeFrame.Scale);
		deltaScale.x = deltaScale.x * currentKeyFramePosition / currentKeyFrameDuration;
		deltaScale.y = deltaScale.y * currentKeyFramePosition / currentKeyFrameDuration;

		auto deltaRotation = (nextFrame.Rotation - activeFrame.Rotation) * currentKeyFramePosition / currentKeyFrameDuration;

		//auto incrementMatrix = SubdivideMatrix(SubMatrix(nextFrameMatrix, activeFrameMatrix), currentKeyFrameDuration);


		auto currentFrame = KeyFrame();

		currentFrame.Position = activeFrame.Position + deltaPosition;
		currentFrame.Scale = activeFrame.Scale + deltaScale;
		currentFrame.Rotation = activeFrame.Rotation + deltaRotation;

		//auto currentTransformMatrix = AddMatrix(activeFrame.Transform.getMatrix(), MultiplyMatrix(incrementMatrix, currentKeyFramePosition));
		
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
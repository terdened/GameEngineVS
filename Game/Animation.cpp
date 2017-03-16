
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
			CurrentTransform = activeFrame.Transform;
			return;
		}

		auto activeFrameMatrix = activeFrame.Transform.getMatrix();
		auto nextFrameMatrix = nextFrame.Transform.getMatrix();

		auto incrementMatrix = SubdivideMatrix(SubMatrix(nextFrameMatrix, activeFrameMatrix), currentKeyFrameDuration);
		auto currentTransformMatrix = AddMatrix(activeFrame.Transform.getMatrix(), MultiplyMatrix(incrementMatrix, currentKeyFramePosition));
		
		CurrentTransform = sf::Transform(currentTransformMatrix[0], currentTransformMatrix[4], currentTransformMatrix[12],
										 currentTransformMatrix[1], currentTransformMatrix[5], currentTransformMatrix[13],
										 currentTransformMatrix[3], currentTransformMatrix[7], currentTransformMatrix[15]);
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
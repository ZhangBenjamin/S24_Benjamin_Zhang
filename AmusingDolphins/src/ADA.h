#pragma once

#include "pch.h"
#include "Utility.h"
#include "AmusingDolphinsEvents.h"

constexpr int AMUSING_DOLPHINS_FRAME_RATE{ 60 };

namespace AmusingDolphins
{
	class AMUSING_DOLPHINS_API AmusingDolphinsApplication
	{
	public:
		AmusingDolphinsApplication();

		virtual void Initialize();
		virtual void OnUpdate();
		virtual void Shutdown();

		void Run();

		void SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunct);
		void SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunct);
		void SetWindowCloseCallback(std::function<void()> callbackFunct);

		void DefaultWindowCloseHandler();

	private:
		std::chrono::steady_clock::time_point mNextFrameTime;
		std::chrono::milliseconds mFrameDuration{ std::chrono::milliseconds{ 1000 } / AMUSING_DOLPHINS_FRAME_RATE };

		bool mShouldContinue{ true };
	};
}



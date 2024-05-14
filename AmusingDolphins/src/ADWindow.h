#pragma once
#include "pch.h"
#include "WindowImpl.h"
#include "Utility.h"
#include "AmusingDolphinsEvents.h"

namespace AmusingDolphins {
	class AMUSING_DOLPHINS_API AmusingDolphinsWindow 
	{
	public:
		static void Init();
		static AmusingDolphinsWindow* GetWindow();
		static void Shutdown();

		void SwapBuffers();
		void PollEvents();
		void Create(int width, int height);
		int GetWidth() const;
		int GetHeight() const;

		void SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunct);
		void SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunct);
		void SetWindowCloseCallback(std::function<void()> callbackFunct);

	private:
		inline static AmusingDolphinsWindow* mInstance{ nullptr };
		std::unique_ptr<WindowImpl> mWindow{ nullptr };

		AmusingDolphinsWindow();
	};
}


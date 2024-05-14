#pragma once

namespace AmusingDolphins {
	class WindowImpl 
	{
	public:
		virtual void Create(int width, int height) = 0;
		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;
		virtual void SwapBuffers() = 0;
		virtual void PollEvents() = 0;

		virtual void SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunct) = 0;
		virtual void SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunct) = 0;
		virtual void SetWindowCloseCallback(std::function<void()> callbackFunct) = 0;
		
		virtual ~WindowImpl() {};
	};
}

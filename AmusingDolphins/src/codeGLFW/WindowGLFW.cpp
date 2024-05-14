#include "pch.h"

#include "WindowGLFW.h"

namespace AmusingDolphins {
	
	WindowGLFW::WindowGLFW()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		
	}

	void WindowGLFW::Create(int width, int height)
	{
		mWindow = glfwCreateWindow(width, height, "MyGame", NULL, NULL);
		assert(mWindow != NULL);
		glfwMakeContextCurrent(mWindow);

		glfwSetWindowUserPointer(mWindow, &mCallbacks);

		glfwSetKeyCallback(mWindow, [](GLFWwindow* window, int keycode, int scancode, int action, int mods) {
			if (action == GLFW_PRESS) {
				Callbacks* callbacks{ (Callbacks*)glfwGetWindowUserPointer(window) };
				
				KeyPressed e{ keycode };
				callbacks->keyPressedFunc(e);
			}
			else if (action == GLFW_RELEASE) {
				Callbacks* callbacks{ (Callbacks*)glfwGetWindowUserPointer(window) };

				KeyReleased e{ keycode };
				callbacks->keyReleasedFunc(e);
			}
			});
		glfwSetWindowCloseCallback(mWindow, [](GLFWwindow* window) {
			Callbacks* callbacks{ (Callbacks*)glfwGetWindowUserPointer(window) };
			callbacks->windowCloseFunc();
			});

	}
	

	void WindowGLFW::SwapBuffers()
	{
		glfwSwapBuffers(mWindow);
	}

	void WindowGLFW::PollEvents()
	{
		glfwPollEvents();
	}

	int WindowGLFW::GetWidth() const
	{
		int width, height;
		glfwGetWindowSize(mWindow, &width, &height);
		return width;
	}

	int WindowGLFW::GetHeight() const
	{
		int width, height;
		glfwGetWindowSize(mWindow, &width, &height);
		return height;
	}

	void WindowGLFW::SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunct)
	{
		mCallbacks.keyPressedFunc = callbackFunct;
	}

	void WindowGLFW::SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunct)
	{
		mCallbacks.keyReleasedFunc = callbackFunct;
	}

	void WindowGLFW::SetWindowCloseCallback(std::function<void()> callbackFunct)
	{
		mCallbacks.windowCloseFunc = callbackFunct;
	}

	WindowGLFW::~WindowGLFW()
	{
		glfwTerminate();
	}
}
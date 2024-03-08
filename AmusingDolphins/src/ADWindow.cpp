#include "pch.h"
#include "ADWindow.h"
#include "codeGLFW/WindowGLFW.h"

namespace AmusingDolphins {
	AmusingDolphinsWindow::AmusingDolphinsWindow()
	{
#ifdef AD_GLFW_WINDOW
		mWindow = std::unique_ptr<WindowImpl>{ new WindowGLFW };
#else
	#definition_AD_GLFW_is_missing
#endif
	}

	void AmusingDolphinsWindow::Init()
	{
		if (!mInstance)
			mInstance = new AmusingDolphinsWindow;
	}

	AmusingDolphinsWindow* AmusingDolphinsWindow::GetWindow()
	{
		return mInstance;
	}

	void AmusingDolphinsWindow::Shutdown()
	{
		if (mInstance) 
			delete mInstance;
		
	}

	void AmusingDolphinsWindow::SwapBuffers()
	{
		mWindow->SwapBuffers();
	}

	void AmusingDolphinsWindow::PollEvents()
	{
		mWindow->PollEvents();
	}

	void AmusingDolphinsWindow::Create(int width, int height) {
		mWindow->Create(width, height);
	}
	int AmusingDolphinsWindow::GetWidth() const
	{
		return mWindow->GetWidth();
	}
	int AmusingDolphinsWindow::GetHeight() const
	{
		return mWindow->GetHeight();
	}
}

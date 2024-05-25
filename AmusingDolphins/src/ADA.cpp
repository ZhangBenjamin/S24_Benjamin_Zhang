#include "pch.h"

#include "ADA.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "ADWindow.h"
#include "stb_image.h"

#include "Renderer.h"
#include "Image.h"
#include "Shader.h"
#include "AmusingDolphinsKeys.h"

namespace AmusingDolphins {
	AmusingDolphinsApplication::AmusingDolphinsApplication()
	{
		AmusingDolphinsWindow::Init();
		AmusingDolphinsWindow::GetWindow()->Create(1000, 800);

		Renderer::Init();
		SetWindowCloseCallback([this]() {DefaultWindowCloseHandler(); });
	}
	void AmusingDolphinsApplication::Initialize()
	{
	}
	void AmusingDolphinsApplication::OnUpdate()
	{
	}
	void AmusingDolphinsApplication::Shutdown()
	{

	}
	void AmusingDolphinsApplication::Run() 
	{
	
		
		
		////////////Delete for final version //////////////////
		//AmusingDolphins::Image pic("..\\AmusingDolphins\\Assets\\Textures\\Test.png"); 
		//////////////////////////////////////////////////////
		Initialize();
		
		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		///////////Delete when workijng on game////////////////////////////
		//int x{ 50 };
		
		//SetKeyPressedCallback([&x](const KeyPressed& event) {
		//	if (event.GetKeyCode() == AD_KEY_RIGHT)
		//		x += 50;
		//	else if (event.GetKeyCode() == AD_KEY_LEFT)
		//		x -= 50;
		//});
		 
		/////////////////////////////////////////////////////////////////////
		while (mShouldContinue)
		{

			
			Renderer::ClearScreen(); 
			OnUpdate();

			///////Delete for final version ///////////////////
			//Renderer::Draw(pic, x, 100);
			//////////////////////////////////////////

			std::this_thread::sleep_until(mNextFrameTime);
			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

			AmusingDolphinsWindow::GetWindow()->SwapBuffers();
			AmusingDolphinsWindow::GetWindow()->PollEvents();
		}

		Shutdown();

		AmusingDolphinsWindow::Shutdown();
	}

	void AmusingDolphinsApplication::SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunct)
	{
		AmusingDolphinsWindow::GetWindow()->SetKeyPressedCallback(callbackFunct);
	}

	void AmusingDolphinsApplication::SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunct)
	{
		AmusingDolphinsWindow::GetWindow()->SetKeyReleasedCallback(callbackFunct);
	}

	void AmusingDolphinsApplication::SetWindowCloseCallback(std::function<void()> callbackFunct)
	{
		AmusingDolphinsWindow::GetWindow()->SetWindowCloseCallback(callbackFunct);
	}

	void AmusingDolphinsApplication::DefaultWindowCloseHandler()
	{
		mShouldContinue = false;
	}
	
}
#include "pch.h"

#include "ADA.h"
#include "ADWindow.h"

namespace AmusingDolphins {
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
		AmusingDolphinsWindow::Init();
		Initialize();
		AmusingDolphinsWindow::GetWindow() -> Create(1000, 800);
		while (true)
		{
			OnUpdate();
			AmusingDolphinsWindow::GetWindow()->SwapBuffers();
			AmusingDolphinsWindow::GetWindow()->PollEvents();
		}

		Shutdown();

		AmusingDolphinsWindow::Shutdown();
	}
	
}
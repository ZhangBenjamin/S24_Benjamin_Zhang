#include "pch.h"

#include "ADA.h"

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
	void AmusingDolphinsApplication::Run() {
		Initialize();

		while (true)
		{
			OnUpdate();
		}

		Shutdown();
	}
}
#pragma once

#include "Utility.h"


namespace AmusingDolphins
{
	class AMUSING_DOLPHINS_API AmusingDolphinsApplication
	{
	public:
		virtual void Initialize();
		virtual void OnUpdate();
		virtual void Shutdown();

		void Run();

	private:

	};
}



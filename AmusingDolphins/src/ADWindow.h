#pragma once
#include "pch.h"
#include "WindowImpl.h"
#include "Utility.h"

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

	private:
		inline static AmusingDolphinsWindow* mInstance{ nullptr };
		std::unique_ptr<WindowImpl> mWindow{ nullptr };

		AmusingDolphinsWindow();
	};
}


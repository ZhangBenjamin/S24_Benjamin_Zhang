#pragma once

#include "Utility.h"
namespace AmusingDolphins
{
	class AMUSING_DOLPHINS_API KeyPressed 
	{
	public:
		KeyPressed(int kCode);

		int GetKeyCode() const;
	private:
		int mKeyCode;
	};

	class AMUSING_DOLPHINS_API KeyReleased 
	{
	public:
		KeyReleased(int kCode);

		int GetKeyCode() const;
	private:
		int mKeyCode;
	};
}

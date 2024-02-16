#include "AmusingDolphins.h"
#include <iostream>


class MyGame : public AmusingDolphins::AmusingDolphinsApplication
{
	virtual void OnUpdate() override
	{
		std::cout << "engine is running" << std::endl;
	}
};

START_GAME(MyGame)
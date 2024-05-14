#include "AmusingDolphins.h"
#include <iostream>


class MyGame : public AmusingDolphins::AmusingDolphinsApplication
{
	virtual void Initialize() 
	{
		
	}
	virtual void OnUpdate() override
	{
		//std::cout << "Window width " <<AmusingDolphins::AmusingDolphinsWindow::GetWindow()->GetWidth() << std::endl;
	}
private:
	

};

START_GAME(MyGame)
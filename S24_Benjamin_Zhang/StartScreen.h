#pragma once
#include "AmusingDolphins.h"
#include <iostream>

class Start 
{
public:
	Start();
	~Start();
	void DisplayStartScreen();

private:
	AmusingDolphins::Image* startScreenImage;
};
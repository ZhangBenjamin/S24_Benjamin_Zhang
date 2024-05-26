#pragma once
#include "AmusingDolphins.h"
#include <iostream>
#include <chrono>
#include <unordered_map>
#include <vector>

class Timer 
{
public:
	Timer();
	void StartTimer();
	void UpdateTimer();
	int GetElapsedTime() const;
	void DisplayTimer() const;

private:
	std::chrono::time_point<std::chrono::steady_clock> start_time;
	int elapsed_time; 

	std::vector<std::string> Numbers = {
		"..\\Assets\\Textures\\Numbers\\Zero.png",
		"..\\Assets\\Textures\\Numbers\\One.png", 
		"..\\Assets\\Textures\\Numbers\\Two.png",
		"..\\Assets\\Textures\\Numbers\\Three.png",
		"..\\Assets\\Textures\\Numbers\\Four.png", 
		"..\\Assets\\Textures\\Numbers\\Five.png", 
		"..\\Assets\\Textures\\Numbers\\Six.png", 
		"..\\Assets\\Textures\\Numbers\\Seven.png", 
		"..\\Assets\\Textures\\Numbers\\Eight.png", 
		"..\\Assets\\Textures\\Numbers\\Nine.png"

	};
};

#pragma once
#include "AmusingDolphins.h"
#include <iostream>
#include <chrono>
#include <unordered_map>
#include <vector>

class Timer : public AmusingDolphins::AmusingDolphinsApplication 
{
public:
	void DisplayTimer() const;

private:
	std::unordered_map<int, std::string> numbers
	{
		{1, "..\\Assets\\Textures\\Numbers\\One.png"}, 
		{2, "..\\Assets\\Textures\\Numbers\\Two.png"}, 
		{3, "..\\Assets\\Textures\\Numbers\\Three.png"},
		{4, "..\\Assets\\Textures\\Numbers\\Four.png"},
		{5, "..\\Assets\\Textures\\Numbers\\Five.png"},
		{6, "..\\Assets\\Textures\\Numbers\\Six.png"},
		{7, "..\\Assets\\Textures\\Numbers\\Seven.png"},
		{8, "..\\Assets\\Textures\\Numbers\\Eight.png"},
		{9, "..\\Assets\\Textures\\Numbers\\Nine.png"},
		{0, "..\\Assets\\Textures\\Numbers\\Zero.png"}
	};
	
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

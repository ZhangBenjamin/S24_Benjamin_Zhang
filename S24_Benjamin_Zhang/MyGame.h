#pragma once
#include "AmusingDolphins.h"
#include "Timer.h"
#include <iostream>
#include <random>
#include <unordered_map>

enum StateOfGame {
	Idle, //The player is currently idle
	Moving, //The player is moving
	Shooting, //The player shoots a bullet
	Dead //The zombie touched the player and is dead
};

enum Direction {
	Left, //The Tank will face left
	Right, //The tank will face right
	Up, //The tank will face up 
	Down //The tank will face down
};

class MyGame : public AmusingDolphins::AmusingDolphinsApplication
{
public:
	//These are my three main functions, other functions are just things to help my code
	virtual void OnUpdate() override;
	virtual void Initialize();
	void RunGame();

	//Getter Functions
	int GetLocationX() const;
	int GetLocationY() const;
	int GetLocationZombieX() const;
	int GetLocationZombieY() const;
	Direction CurrentDirection(); 
	StateOfGame TankAction() const;

	//Setter Functions
	void ChangeDirection(const Direction& direction);
	void ChangeLocationOfZombie(const int& x, const int& y);
	void ChangeLocationOfTank(const int& x, const int& y);
	void ChangeStateOfTank(StateOfGame state);

	//Other Zombie Functions
	void RandomizeZombieSpawn();
	bool CollidesWithZombie();
	bool BulletCollidesWIthZombie();
	void DeleteZombie(const int& x, const int& y);
	void MoveIdleZombies();

	


private:
	//Location of tank
	int location_x{ 0 };
	int location_y{ 0 };

	//Location of zombie
	int location_zombie_x{ 500 };
	int location_zombie_y{ 500 };
	std::vector<AmusingDolphins::Unit> position_zombie;
	bool isIdle{ false };
	Direction direction_zombie{ Left };

	//Location of bullet
	int location_bullet_x{ location_x };
	int location_bullet_y{ location_y };
	bool isShooting{ false };
	Direction direction_bullet;
	

	//Direction and state of the tank
	Direction currentDirection{ Left };
	StateOfGame StateOfTank{ Idle };

	//Timer
	Timer timer;
	
};
	


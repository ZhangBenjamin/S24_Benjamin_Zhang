#include "MyGame.h"


void MyGame::OnUpdate() 
{
	AmusingDolphins::Renderer::ClearScreen();
	AmusingDolphins::Image background("..\\Assets\\Textures\\concrete_background.png");
	AmusingDolphins::Renderer::Draw(background, 0, 0);
	RunGame();

	if (CollidesWithZombie()) {
		ChangeStateOfTank(Dead);
		std::cout << "Hit zombie" << std::endl;
		AmusingDolphins::Renderer::ClearScreen();
	}
}

void MyGame::Initialize()
{
	

}

void MyGame::RunGame()
{
	
	//Images listed here
	AmusingDolphins::Image tank_left("..\\Assets\\Textures\\tank_left.png");
	AmusingDolphins::Image tank_right("..\\Assets\\Textures\\tank_right.png");
	AmusingDolphins::Image tank_up("..\\Assets\\Textures\\tank_up.png");
	AmusingDolphins::Image tank_down("..\\Assets\\Textures\\tank_down.png");
	AmusingDolphins::Image tank_bullet("..\\Assets\\Textures\\cannonball.png");
	

	
	SetKeyPressedCallback([&](const AmusingDolphins::KeyPressed& event) {
		if (event.GetKeyCode() == AD_KEY_RIGHT) {
			ChangeStateOfTank(Moving);
			location_x += 50;
			if (location_x + 50 > 1000) {
				location_x -= 50;
			}
			ChangeDirection(Right);
		}
		else if (event.GetKeyCode() == AD_KEY_LEFT) {
			ChangeStateOfTank(Moving);
			location_x -= 50;
			if (location_x - 50 < -50) {
				location_x += 50;
			}
			ChangeDirection(Left);
		}
		else if (event.GetKeyCode() == AD_KEY_UP) {
			ChangeStateOfTank(Moving);
			location_y += 50;
			if (location_y + 50 > 800) {
				location_y -= 50;
			}
			ChangeDirection(Up);
		}
		else if (event.GetKeyCode() == AD_KEY_DOWN) {
			ChangeStateOfTank(Moving);
			location_y -= 50;
			if (location_y - 50 < -50) {
				location_y += 50;
			}
			ChangeDirection(Down);
		}
		else if (event.GetKeyCode() == AD_KEY_SPACE) {
			ChangeStateOfTank(Shooting);
			Shoot(CurrentDirection(), TankAction());
		}
		else {
			ChangeStateOfTank(Idle);
		}
		});
	//AmusingDolphins::Renderer::Draw(tank_bullet, 150, 150);
	RandomizeZombieSpawn();
	
	

	if (CurrentDirection() == Left) {
		AmusingDolphins::Renderer::Draw(tank_left, GetLocationX(), GetLocationY());
	}
	else if (CurrentDirection() == Right) {
		AmusingDolphins::Renderer::Draw(tank_right, GetLocationX(), GetLocationY());
	}
	else if (CurrentDirection() == Up) {
		AmusingDolphins::Renderer::Draw(tank_up, GetLocationX(), GetLocationY());

	}
	else if (CurrentDirection() == Down) {
		AmusingDolphins::Renderer::Draw(tank_down, GetLocationX(), GetLocationY());
	}
	
	


}

int MyGame::GetLocationX() const
{
	return location_x;
}

int MyGame::GetLocationY() const
{
	return location_y;
}

int MyGame::GetLocationZombieX() const
{
	return location_zombie_x;
}

int MyGame::GetLocationZombieY() const
{
	return location_zombie_y;
}

Direction MyGame::CurrentDirection()
{
	return currentDirection;
}

void MyGame::ChangeDirection(const Direction& direction)
{
	currentDirection = direction;
}

void MyGame::ChangeLocationOfZombie(const int& x, const int& y)
{
	location_zombie_x = x;
	location_zombie_y = y;
}

void MyGame::ChangeLocationOfTank(const int& x, const int& y)
{
	location_x = x;
	location_y = y;
}

void MyGame::Shoot(const Direction& direction, const StateOfGame& state) const
{
	AmusingDolphins::Image tank_bullet("..\\Assets\\Textures\\cannonball.png");
	AmusingDolphins::Renderer::Draw(tank_bullet, 100, 100);

	if (direction == Left) {
		AmusingDolphins::Renderer::Draw(tank_bullet, 100, 100);
	}
	else if (direction == Right) {
		AmusingDolphins::Renderer::Draw(tank_bullet, 150, 150);
	}
	else if (direction == Up) {
		AmusingDolphins::Renderer::Draw(tank_bullet, 200, 200);
	} 
	else if (direction == Down) {
		AmusingDolphins::Renderer::Draw(tank_bullet, 250, 250);
	}
	
}

StateOfGame MyGame::TankAction() const
{
	return StateOfTank;
}

void MyGame::ChangeStateOfTank(StateOfGame state)
{
	StateOfTank = state;
}

void MyGame::RandomizeZombieSpawn()
{

	AmusingDolphins::Image Zombie("..\\Assets\\Textures\\Zombie.png");
	
	std::default_random_engine generator;
	std::uniform_int_distribution<int> random_x(1, 1000);
	std::uniform_int_distribution<int> random_y(1, 800);
	ChangeLocationOfZombie(random_x(generator), random_y(generator));
	AmusingDolphins::Renderer::Draw(Zombie, location_zombie_x, location_zombie_y);

	
}

bool MyGame::CollidesWithZombie()
{
	if (GetLocationX() - GetLocationZombieX() == 50 || GetLocationY() - GetLocationZombieY() == 50
		|| GetLocationX() - GetLocationZombieX() == -50 || GetLocationY() - GetLocationZombieY() == -50) {
		return true;
	}
	return false;
	
}


#include "MyGame.h"


void MyGame::OnUpdate() 
{
	AmusingDolphins::Renderer::ClearScreen();
	AmusingDolphins::Image background("..\\Assets\\Textures\\concrete_background.png");
	AmusingDolphins::Renderer::Draw(background, 0, 0);
	RandomizeZombieSpawn();
	RunGame();

	timer.UpdateTimer();
	timer.DisplayTimer();
	
}

void MyGame::Initialize()
{
	timer.StartTimer();
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
		if (event.GetKeyCode() == AD_KEY_RIGHT || event.GetKeyCode() == AD_KEY_D) {
			ChangeStateOfTank(Moving);
			location_x += 50;
			if (location_x + 50 > 1000) {
				location_x -= 50;
			}
			ChangeDirection(Right);
			std::cout << "Moved Right" << std::endl;
		}
		else if (event.GetKeyCode() == AD_KEY_LEFT || event.GetKeyCode() == AD_KEY_A) {
			ChangeStateOfTank(Moving);
			location_x -= 50;
			if (location_x - 50 < -50) {
				location_x += 50;
			}
			ChangeDirection(Left);
			std::cout << "Moved Left" << std::endl;
		}
		else if (event.GetKeyCode() == AD_KEY_UP || event.GetKeyCode() == AD_KEY_W) {
			ChangeStateOfTank(Moving);
			location_y += 50;
			if (location_y + 50 > 800) {
				location_y -= 50;
			}
			ChangeDirection(Up);
			std::cout << "Moved Up" << std::endl;
		}
		else if (event.GetKeyCode() == AD_KEY_DOWN || event.GetKeyCode() == AD_KEY_S) {
			ChangeStateOfTank(Moving);
			location_y -= 50;
			if (location_y - 50 < -50) {
				location_y += 50;
			}
			ChangeDirection(Down);
			std::cout << "Moved Down" << std::endl;
		}
		else if (event.GetKeyCode() == AD_KEY_SPACE) {
			std::cout << "Pressed Space" << std::endl;
			ChangeStateOfTank(Shooting);
			if (!isShooting) {
				isShooting = true;
				location_bullet_x = location_x + 25;
				location_bullet_y = location_y + 30;
				direction_bullet = CurrentDirection();
			}
		}
		else if (event.GetKeyCode() == AD_KEY_Q) {
			std::cout << "Quit Game" << std::endl;
			AmusingDolphins::Renderer::ClearScreen();
		}
		else {
			ChangeStateOfTank(Idle);
		}
		});
	if (isShooting) {
		switch (direction_bullet) {
		case Left:
			location_bullet_x -= 20;
			if (location_bullet_x < 0) isShooting = false;
			break;
		case Right:
			location_bullet_x += 20;
			if (location_bullet_x > 1000) isShooting = false;
			break;
		case Up:
			location_bullet_y += 20;
			if (location_bullet_y > 800) isShooting = false;
			break;
		case Down:
			location_bullet_y -= 20;
			if (location_bullet_y < 0) isShooting = false;
			break;
		}
		AmusingDolphins::Renderer::Draw(tank_bullet, location_bullet_x, location_bullet_y);

		
		if (BulletCollidesWIthZombie()) {
			isShooting = false;
			std::cout << "Bullet hit a zombie!" << std::endl;
		}
	}
	
	
	if (CollidesWithZombie()) {
		std::cout << "Tank hit a zombie!" << std::endl;
		location_x = 0;
		location_y = 0;
	}	
	//Movement of tank
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
	std::uniform_int_distribution<int> random_x(200, 900);
	std::uniform_int_distribution<int> random_y(200, 600);

	for (int i = 0; i < 10; ++i) {
		ChangeLocationOfZombie(random_x(generator), random_y(generator));
		position_zombie.push_back({ "..\\Assets\\Textures\\Zombie.png", location_zombie_x, location_zombie_y });
		AmusingDolphins::Renderer::Draw(position_zombie[i]);
	}
}

bool MyGame::CollidesWithZombie()
{
	int tank_size = 50;
	int zombie_size = 50;

	for (const AmusingDolphins::Unit& pos : position_zombie) {
		if (location_x < pos.GetXCoord() + zombie_size &&
			location_x + tank_size > pos.GetXCoord() &&
			location_y < pos.GetYCoord() + zombie_size &&
			location_y + tank_size > pos.GetYCoord()) {
			return true;
		}
	}
	return false;
	
}

bool MyGame::BulletCollidesWIthZombie()
{
	int bullet_size = 20;
	int zombie_size = 50;

	for (const AmusingDolphins::Unit& pos : position_zombie) {
		if (location_bullet_x < pos.GetXCoord() + zombie_size &&
			location_bullet_x + bullet_size > pos.GetXCoord() &&
			location_bullet_y < pos.GetYCoord() + zombie_size &&
			location_bullet_y + bullet_size > pos.GetYCoord()) {
			DeleteZombie(pos.GetXCoord(), pos.GetYCoord());
			return true;
		}
	}
	return false;
	
}

void MyGame::DeleteZombie(const int& x, const int& y)
{
	int bullet_size = 20;
	int zombie_size = 50;
	for (int i = 0; i < position_zombie.size(); ++i) {
		if (position_zombie[i].GetXCoord() == x && position_zombie[i].GetYCoord() == y) {
			position_zombie.erase(position_zombie.begin() + i);
			break;
		}
	}
}

void MyGame::MoveIdleZombies()
{
}

    

#pragma once
#include "struct.h"
#include "Novice.h"
#include "Bullet.h"
class Player: public Bullet {

	public:

	Player(int x, int y, int radius, int speed);

	~Player();

	void Initialize();

	void Update(char* keys, char* preKeys);

	void Move(char* keys, char* preKeys);

	void Draw();

	public:
	PlayerStruct player;
	//Bullet* bullet = new Bullet();


};

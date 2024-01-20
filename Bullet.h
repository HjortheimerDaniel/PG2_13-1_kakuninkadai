#pragma once
#include "struct.h"
#include "Novice.h"
class Bullet {

	public:

	Bullet();

	~Bullet();

	void InitializeBullet();

	void Shot();

	void UpdateBullet();

	void SetBulletX(int x, int index) { bullet.x[index] = x; };

	void SetBulletY(int y, int index) { bullet.y[index] = y; };



	void SetIsShot(bool shot, int index) { 
		
			bullet.isShot[index] = shot;
	};

	bool* GetIsShot() { return bullet.isShot; };

	void DrawBullet();

	public:
		BulletStruct bullet;


};

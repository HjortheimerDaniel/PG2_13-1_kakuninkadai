#pragma once
#include "Novice.h"
class Enemy {

	public:

		static bool isAlive;

		Enemy(int posX, int posY, int speedX, int speedY);

		~Enemy() {};

		void Update();

	    int GetPosX() { return posX_; };

	    int GetPosY() { return posY_; };

	    int GetRadius() { return radius_; };

	    int GetSpeedX() { return speedX_; };

	    int GetSpeedY() { return speedY_; };

	    void SetSpeedX(int speedX) { speedX_ = speedX; };

	    void SetSpeedY(int speedY) { speedY_ = speedY; };

	    void Draw();

		private:

			int posX_, posY_, speedX_, speedY_, radius_;

};

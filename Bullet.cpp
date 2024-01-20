#include "Bullet.h"

Bullet::Bullet() {
	bullet.radius = 20;
	for (int i = 0; i < 10; i++) {
	
		bullet.speed[i] = 8;
		bullet.x[i] = -100;
		bullet.y[i] = 200;
		bullet.isShot[i] = false;
	}

}

void Bullet::InitializeBullet() {

	bullet.radius = 10;
	for (int i = 0; i < 10; i++) {

		bullet.speed[i] = 8;
		bullet.x[i] = -100;
		bullet.y[i] = 200;
		bullet.isShot[i] = false;
	}

}



void Bullet::Shot() {
	for (int i = 0; i < 10; i++) {

		if (bullet.isShot[i]) {
			bullet.y[i] -= bullet.speed[i];
		}

		if (bullet.y[i] <= -30) {
			bullet.isShot[i] = false;
		}
	}

}

void Bullet::UpdateBullet() {

	Shot();

}

void Bullet::DrawBullet() {

		for (int i = 0; i < 10; i++) {
		if (bullet.isShot[i]) {

			Novice::DrawEllipse(
			    bullet.x[i], bullet.y[i], bullet.radius, bullet.radius, 0.0f, BLACK,
			    kFillModeSolid);
		}
	}


}


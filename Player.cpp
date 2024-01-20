#include "Player.h"

Player::Player(int x, int y, int radius, int speed) {
	
	player.radius_ = radius;
	player.x_ = x;
	player.y_ = y;
	player.speed_ = speed;
	bullet.radius = 10;
	for (int i = 0; i < 10; i++) {

		bullet.speed[i] = 8;
		bullet.x[i] = -100;
		bullet.y[i] = 200;
		bullet.isShot[i] = false;
	}

}

Player::~Player() {}

void Player::Initialize() {

	
	InitializeBullet();
	

}

void Player::Update(char* keys, char* preKeys) {

	Move(keys, preKeys);
	UpdateBullet();

}

void Player::Move(char* keys, char* preKeys) {

	if (keys[DIK_D]) {
		player.x_ += player.speed_;
	}
	if (keys[DIK_A]) {
		player.x_ -= player.speed_;
	}
	if (keys[DIK_W]) {
		player.y_ -= player.speed_;
	}
	if (keys[DIK_S]) {
		player.y_ += player.speed_;
	}
	for (int i = 0; i < 10; i++) {

		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && !bullet.isShot[i]) {
			bullet.isShot[i] = true;
			bullet.x[i]  = player.x_;
			bullet.y[i] = player.y_ - 30;
			break;
			
			
		}
	}

}

void Player::Draw() {
		DrawBullet();
		Novice::DrawEllipse(player.x_, player.y_, player.radius_, player.radius_, 0.0f, WHITE, kFillModeSolid);


}

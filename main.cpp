#include <Novice.h>
#include "Enemy.h"
#include "Player.h"
#include "Struct.h"

const char kWindowTitle[] = "GC1B_07_ジュットハイマー_ダニエル_タイトル";

	bool Enemy::isAlive = true;

	

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};
	Player* player = new Player(200, 500, 40, 5);
	Enemy* enemy[2];

	enemy[0] = new Enemy(10, 200, 3, 0);
	enemy[1] = new Enemy(500, 300, 3, 0);


	int distX[10];
	int distY[10];
	int dist[10];
	int radius[2];
		
		
		// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		player->Update(keys, preKeys);
		for (int i = 0; i < 2; i++) {
			enemy[i]->Update();
		}
		for (int j = 0; j < 2; j++) {
		
			for (int i = 0; i < 10; i++) {

				distX[i] = enemy[j]->GetPosX() - player->bullet.x[i];
				distY[i] = enemy[j]->GetPosY() - player->bullet.y[i];
				dist[i] = (distX[i] * distX[i]) + (distY[i] * distY[i]);
				radius[j] = enemy[0]->GetRadius() + player->bullet.radius;
				if (dist[i] <= radius[j] * radius[j]) {
					Enemy::isAlive = false;
				}
			}
		}

		if (keys[DIK_R]) {
			Enemy::isAlive = true;
		}
			
		

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		player->Draw();
		for (int i = 0; i < 2; i++) {
			enemy[i]->Draw();
		}

		Novice::ScreenPrintf(0, 0, "enemyA isAlive = %d", enemy[0]->isAlive);
		Novice::ScreenPrintf(0, 20, "enemyB isAlive = %d", enemy[1]->isAlive);
		Novice::ScreenPrintf(0, 40, "WASD : player Move");
		Novice::ScreenPrintf(0, 60, "shot : SPACE");
		Novice::ScreenPrintf(0, 80, "enemy Respawn : R");

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}
	for (int i = 0; i < 2; i++) {
		delete enemy[i];
	}
	delete player;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}

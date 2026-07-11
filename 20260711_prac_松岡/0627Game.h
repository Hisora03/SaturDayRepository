#pragma once
#include "0627MoleManager.h"
///=========================================
/// ゲーム全体を管理するクラス
/// ・スコア管理
/// ・終了
///=========================================
class Game
{
private:
	MoleManager moleManager;

	int score;

	int backGraound;
	int normalImage;
	int hitImage;
	int hitSound;

public:
	//コンストラクタ
	Game();
	//更新
	void Update(float dt, int mx, int my, bool click);
	//描画
	void Draw();

};



#include "0627Game.h"
#include "0627MoleManager.h"
#include "DxLib.h"

///=========================================
/// 初期化 
///=========================================
Game::Game()
{
	//スコアの初期化
	score = 0;
	backGraound = LoadGraph("image/background.png");
	normalImage = LoadGraph("image/mole.png");
	hitImage = LoadGraph("image/mole_hit.png");
	//サウンド読み込み
	hitSound = LoadSoundMem("Sound/Punching_Sound.mp3");

	//モグラを最初から複数用意（今回は4体）
	moleManager.Init(4);

}


///=========================================
/// 更新 
///=========================================
void Game::Update(float dt, int mx, int my, bool click)
{
	moleManager.Update(dt);
	if (click)
	{
		if (moleManager.HandClick(mx, my))
		{
			//スコア加算
			score += 5;
			PlaySoundMem(hitSound, DX_PLAYTYPE_BACK);
		}
	}
}
///=========================================
/// 描画
///=========================================
void Game::Draw()
{
	//背景を描画
	DrawGraph(0, 0, backGraound, TRUE);
	moleManager.Draw(normalImage, hitImage);
	SetFontSize(30);
	DrawFormatString(10, 10, GetColor(255, 255, 255), "Score:%d", score);

}
#include "Game.h"
#include "DxLib.h"

///=========================================
/// 初期化 
///=========================================
Game::Game()
{
	//imageフォルダに入っている画像に番号をつけて保存
	backGround = LoadGraph("img/Back.jpeg");
	normalImage = LoadGraph("img/OIP.webp");
	hitImage = LoadGraph("img/hit.jpg");

	

	//最初はステージ1から
	stage = 1;

	//最初はまだクリアしてない
	isGameClear = false;

	//ステージ1の準備を呼び出す
	StartStage();


}

///=========================================
/// ステージ開始の準備
///=========================================
void Game::StartStage()
{
	//シャボン玉の数は"ステージ数 ＋ 2"
	bubblesCount = stage + 2;

	//もし配列の限界を超えそうなら25で止める
	if (bubblesCount > 15) bubblesCount = 15;

	//画像の元サイズを調べる
	int imgW, imgH;
	GetGraphSize(normalImage, &imgW, &imgH);

	//10分の1にしたサイズを計算しておく
	int w10 = imgW / 10;
	int h10 = imgH / 10;

	//シャボン玉の初期位置をランダムに
	for (int i = 0; i < bubblesCount; i++)
	{
		//画面からはみ出さないようにする
		backX[i] = GetRand(800 - w10);
		backY[i] = GetRand(600 - h10);

		//復活
		bubblesState[i] = 1;

		// タイマーも 0 にリセット
		bubblesTimer[i] = 0.0f;
	}


}


/// 更新 

void Game::Update(float dt, int mx, int my, bool click)
{
	//すでに全クリア状態なら、これ以上お化けの計算はしない
	if (isGameClear == true)
	{
		return;
	}

	// 画像のサイズ
	int imgW, imgH;
	GetGraphSize(normalImage, &imgW, &imgH);

	//10分の1のサイズを計算
	int w10 = imgW / 10;
	int h10 = imgH / 10;

	//割れたシャボン玉のタイマーを進める処理
	for (int i = 0; i < bubblesCount; i++)
	{
		if (bubblesState[i] == 2)
		{
			bubblesTimer[i] += dt; 

			if (bubblesTimer[i] >= 1.0f) 
			{
				bubblesState[i] = 0;
			}
		}
	}

	//クリックされた時の処理
	if (click)
	{
		for (int i = 0; i < bubblesCount; i++)
		{
			if (bubblesState[i] != 1) continue;

		
			if (mx >= backX[i] && mx <= (backX[i] + w10) &&
				my >= backY[i] && my <= (backY[i] + h10))
			{
				bubblesState[i] = 2;
				break;
			}
		}
	}

	//画面にシャボン玉がないか
	int aliveLeft = 0;
	for (int i = 0; i <bubblesCount; i++)
	{
		if (bubblesState[i] == 1 || bubblesState[i] == 2)
		{
			aliveLeft++; 
		}
	}

	
	if (aliveLeft == 0)
	{
		stage++; 

		if (stage <= 10)
		{
			StartStage(); 
		}
		else
		{
			//全クリフラグ
			isGameClear = true;

		}
	}
}

///=========================================
/// 描画
///=========================================
void Game::Draw()
{

	DrawExtendGraph(0, 0, 800, 600, backGround, TRUE);

	//全クリア状態なら、クリア画面を描画して終了
	if (isGameClear == true)
	{
		
		DrawBox(100, 200, 700, 400, GetColor(0, 0, 0), TRUE);

		// 文字のサイズを60サイズに
		SetFontSize(60);

		DrawString(200, 250, "ALL STAGE CLEAR!", GetColor(255, 255, 0));

		return;
	}

	// 画像のサイズを取得
	int imgW, imgH;
	GetGraphSize(normalImage, &imgW, &imgH);

	//ここでも10分の1のサイズを計算
	int w10 = imgW / 10;
	int h10 = imgH / 10;

	//浮いてるシャボン玉
	for (int i = 0; i < bubblesCount; i++)
	{
		
		if (bubblesState[i] == 1)
		{
			
			DrawExtendGraph(backX[i], backY[i], backX[i] + w10, backY[i] + h10, normalImage, TRUE);
		}
		else if (bubblesState[i] == 2) 
		{
			DrawExtendGraph(backX[i], backY[i], backX[i] + w10, backY[i] + h10, hitImage, TRUE);
		}
	}

	//今何ステージ目かを画面の左上に文字で出す
	DrawFormatString(20, 20, GetColor(255, 255, 0), "STAGE: %d", stage);
}
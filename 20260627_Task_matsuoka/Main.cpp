#include"DxLib.h"
#include "Game.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	
	ChangeWindowMode(TRUE);
	
	SetGraphMode(800, 600, 32);
	SetDrawScreen(DX_SCREEN_BACK);
	
	if (DxLib_Init() == -1) return -1;

	//インスタンス
	Game game;
	//変数
	int prevTime = GetNowCount();
	int prevMouse = 0;
	while (ProcessMessage() == 0 &&
		CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//前回のループから今回までに何秒かかったか
		int nowTimer = GetNowCount();
		float dt = (nowTimer - prevTime) / 1000.0f;
		prevTime = nowTimer;
		//XとY座標
		int mx, my;
		GetMousePoint(&mx, &my);
		int mouse = GetMouseInput();
		bool click = false;

		if ((mouse & MOUSE_INPUT_LEFT) && !(prevMouse & MOUSE_INPUT_LEFT))
		{
			click = true;
		}
		prevMouse = mouse;

		//更新
		game.Update(dt, mx, my, click);
		//画面
		ClearDrawScreen();
		//描画
		game.Draw();
		//表画面に表示
		ScreenFlip();
	}
	//Dxlibを終了
	DxLib_End();
	//処理を終了
	return 0;
}
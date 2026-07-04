#include"DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(TRUE);
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetGraphMode(800, 600, 32);
	if (DxLib_Init() == -1)return-1;

	int fontColor = GetColor(255, 100, 0);

	while (ProcessMessage()==0&&CheckHitKey(KEY_INPUT_ESCAPE)==0)
	{
		ClearDrawScreen();

		SetFontSize(120);
		DrawFormatString(75, 250, fontColor, "Just Do It");

		ScreenFlip();
	}
	DxLib_End();

	return 0;
}
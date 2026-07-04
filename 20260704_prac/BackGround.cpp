#include "BackGround.h"
#include"DxLib.h"

//‰Šú‰»
void BackGround::Init()
{
	imageHandle = LoadGraph("img/BackGround.png");
}

//•`‰æ
void BackGround::Draw(float cameraX)
{
	DrawGraph(-(int)(cameraX * 0.5f), 0, imageHandle, TRUE);
}
#include "Camera.h"
#include"DxLib.h"
#include"Config.h"

//コンストラクタ
Camera::Camera()
{
	x = 0.0f;
}

//更新
void Camera::Update()
{
	//Aキーで左移動
	if (CheckHitKey(KEY_INPUT_A)) { x -= GameConst::CAMARA_SPEED; }
	//Dキーで右移動
	if (CheckHitKey(KEY_INPUT_D)) { x -= GameConst::CAMARA_SPEED; }
	//画面外二でないように制限
	if (x < 0) { x = 0; }
	if (x > GameConst::SCREEN_WINDTH) { x = GameConst::SCREEN_WINDTH; }
}

//x座標取得
float Camera::GetX() const
{
	return x;
}
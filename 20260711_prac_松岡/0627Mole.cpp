#include "0627Mole.h"

//コンストラクタ
Mole::Mole()
{
	x = 0;
	y = 0;
	timer = 0.0f;
	state = &g_HiddenState;
}

//=============================
//更新
//=============================
void Mole::Update(float dt)
{
	state->Update(*this, dt);
}
//=============================
//描画
//=============================
void Mole::Draw(int normalImag, int hitImage)
{
	state->Draw(*this, normalImag, hitImage);
}
//=============================
//ヒット
//=============================
bool Mole::IsHit(int mx, int my)
{
	return state->OnClick(*this, mx, my);
}
//=============================
//状態変化
//=============================
void Mole::ChangeState(IMoleState* newState)
{
	timer = 0.0f;
	state = newState;
}
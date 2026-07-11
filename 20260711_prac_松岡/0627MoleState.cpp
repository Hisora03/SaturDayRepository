#include "0627MoleState.h"
#include "0627Mole.h"
#include "DxLib.h"

//共有インスタンス
HiddenState g_HiddenState;
VisibleState g_VisibleState;
HitState g_HitState;

//================================
//Hidden(非表示)
//================================
//更新
void HiddenState::Update(Mole& mole, float dt)
{
	//時間経過
	mole.timer += dt;
	//1秒経過したら
	if (mole.timer >= 1.0f)
	{
		mole.x = GetRand(700 - 10) + 10;
		mole.y = GetRand(500 - 10) + 10;
		//状態を表示に切り替える
		mole.ChangeState(&g_VisibleState);
	}
}
//描画
void HiddenState::Draw(Mole&, int, int) {}
//クリック
bool HiddenState::OnClick(Mole&, int, int) { return false; }

//================================
//Visible(表示)
//================================
//更新
void VisibleState::Update(Mole& mole, float dt)
{
	mole.timer += dt;
	if (mole.timer >= 2.0f)
	{
		mole.ChangeState(&g_HiddenState);
	}
}
//描画
void VisibleState::Draw(Mole& mole, int normalImg, int)
{
	DrawExtendGraph((int)mole.x, (int)mole.y,
		(int)mole.x + 75, (int)mole.y + 75,
		normalImg, TRUE);
}
//クリック
bool VisibleState::OnClick(Mole& mole, int mx, int my)
{
	//当たり判定
	if (mx >= mole.x && mx <= mole.x + 75 &&
		my >= mole.y && my <= mole.y + 75)
	{
		mole.ChangeState(&g_HitState);
		return true;
	}

	return false;
}

//================================
//Hit(叩かれた)
//================================
//更新
void HitState::Update(Mole& mole, float dt)
{
	mole.timer += dt;
	if (mole.timer >= 0.5f)
	{
		mole.ChangeState(&g_HiddenState);

	}

}
//描画
void HitState::Draw(Mole& mole, int, int hitImage)
{
	DrawExtendGraph((int)mole.x, (int)mole.y,
		(int)mole.x + 75, (int)mole.y + 75,
		hitImage, TRUE);
}
//クリック
bool HitState::OnClick(Mole& mole, int mx, int my) { return false; }
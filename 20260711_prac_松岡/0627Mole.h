#pragma once
#include"0627MoleState.h"
///=========================================
/// モグラ個体クラス
/// ・位置
/// ・状態
/// ・タイマー
///=========================================

class  Mole
{
public:
	float x, y;		//モグラの座標
	float timer;	//モグラのタイマー
	IMoleState* state;	//モグラの状態管理インターフェース

	//コンストラクタ
	Mole();

	void Update(float dt);
	void Draw(int normalImag, int hitImage);
	bool IsHit(int mx, int my);
	void ChangeState(IMoleState* newState);

};


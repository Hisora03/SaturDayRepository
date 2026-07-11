#pragma once
#include <vector>
#include "0627Mole.h"

//=========================================
//モグラ複数管理クラス
//・初期化
//・更新
//・描画
//・クリック判定の集約
//=========================================

class  MoleManager
{
private:
	//モグラの数を保持
	std::vector<Mole> moles;
public:
	//モグラ生成
	void Init(int count);

	//モグラ更新
	void Update(float dt);

	//モグラ描画
	void Draw(int normalImg, int hitImg);

	//全モグラクリア判定
	bool HandClick(int mx, int my);

};


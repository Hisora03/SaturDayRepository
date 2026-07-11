#pragma once

class Game
{
private:
	int backGround;
	int normalImage;
	int hitImage;


	
	int backX[15];
	int backY[15];

	// 3つの状態（0:消える, 1:浮く, 2:割れた）
	int bubblesState[15];

	//シャボン玉が割れた後からの時間をカウントする
	float bubblesTimer[15];

	//ステージ管理用の変数
	int stage;		// 今のステージ番号（1〜10）
	int bubblesCount;// 今のステージで画面に出るシャボン玉の数

	//全ステージクリアしたかどうかのフラグ
	bool isGameClear;

public:
	//コンストラクタ
	Game();
	//更新
	void Update(float dt, int mx, int my, bool click);
	//描画
	void Draw();
	//新しくステージを始めるときの初期化関数
	void StartStage();
};

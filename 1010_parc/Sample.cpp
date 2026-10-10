#include<iostream>
using namespace std;

//playerクラスを定義
class Player
{
public:
	int hp = 100;
	//プレイヤーにダメージを与える関数
	void Dmage(int damage)
	{
		hp -= 10;
	}
};
int main(void)
{
	//playerのオブジェクトをインスタンス化
	Player player;

	//playerのオブジェクトをアドレスをポインタに保存する
	Player* pPlayer = &player;

	//ポインタｗｐを使って、ダメージ関数を呼び出すこともできる
	pPlayer->Dmage(10);
	cout << "Player:HP" << player.hp << endl;
	return 0;

}

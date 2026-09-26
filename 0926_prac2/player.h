#pragma once

#include"Collision.h"

class Player
{
private:
	//プレイヤーの位置
	float x;
	float y;
	//プレイヤーの移動速度
	float width;
	float height;

	//ジャンプフラグ
	bool isJumping;

	//プレイヤーの当たり判定
	Collision collision;

	//足元の当たり判定
	Collision footCollision;

	//頭の当たり判定
	Collision headCollision;



public:
	Player();
	
};
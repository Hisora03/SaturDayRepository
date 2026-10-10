#pragma once

#include <vector>
#include <string>
using namespace std;
class Map
{
private:
	//マップチップの番号
	vector<vector<int>>mapDate;
	//当たり判定の情報
	vector<vector<int>>hitDate;

	//マップチップの画像
	int chipImage[64];

	//マップの縦横のマスの数
	int mapWidth;
	int mapHeight;

	//マップの大きさ
	static constexpr int CHIP_SIZE = 64;

	//csvファイルの読み込み
	bool LoadCSV(const char* fileName, vector<vector<int>>& data);
public:
	/// <summary>
	/// Mapコンストラクタ
	/// </summary>
	Map();
	/// <summary>
	/// 初期化
	/// </summary>
	/// <returns>読み込み不正</returns>
	bool Init();
	/// <summary>
	/// マップの描画
	/// </summary>
	/// <param name="cameraX">カメラ座標X</param>
	/// <param name="cameraY">カメラ座標Y</param>
	void Draw(float cameraX, float cameraY);
	/// <summary>
	/// 通行できるかどうか
	/// </summary>
	/// <param name="tileX">タイルのX座標</param>
	/// <param name="tileY">タイルのY座標</param>
	/// <returns>通過可能判定</returns>
	bool IsSolid(int tileX, int tileY);
	/// <summary>
	/// ワールド座標カラ当たり判定を調べる
	/// </summary>
	/// <param name="worldX"></param>
	/// <param name="worldY"></param>
	/// <returns></returns>
	bool IsSolidAt(float worldX, float worldY);

};

#pragma once
class Mole;
//状態インターフェース
class IMoleState
{
public:
	virtual void Update(Mole& mole, float dt) = 0;
	virtual void Draw(Mole& mole, int normalImg, int hitImag);
	virtual bool OnClick(Mole& mole, int mx, int my) = 0;
};

//各状態
//非表示
class HiddenState : public IMoleState
{
public:
	void Update(Mole& mole, float dt) override;
	void Draw(Mole& mole, int, int) override;
	bool OnClick(Mole& mole, int, int) override;
};
//表示
class VisibleState : public IMoleState
{
public:
	void Update(Mole& mole, float dt) override;
	void Draw(Mole& mole, int normalImg, int) override;
	bool OnClick(Mole& mole, int mx, int my) override;
};
//Hit
class HitState : public IMoleState
{
public:
	void Update(Mole& mole, float dt) override;
	void Draw(Mole& mole, int, int hitImag) override;
	bool OnClick(Mole& mole, int mx, int my) override;
};

//共有インスタンス
extern HiddenState g_HiddenState;
extern VisibleState g_VisibleState;
extern HitState g_hitState; 

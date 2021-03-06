#ifndef _BREAKWALL_H_
#define _BREAKWALL_H_

#include "..\FrameWork\define.h"
#include "BaseObject.h"
#include "..\Framework\IComponent.h"
#include "CollisionBody.h"
#include "../FrameWork/Animation.h"
#include "../Framework/StopWatch.h"
#include "QuadtreeNode.h"
#include "Crown.h"
class BreakWall : public BaseObject
{
public:
	BreakWall(int x, int y, int itemX = 0, int itemY = 0);


	void init() override;
	void update(float deltatime) override;
	void draw(LPD3DXSPRITE, Viewport*) override;
	void release() override;
	RECT getBounding() override;

	bool isBroken();

	void wasHit();

	void setColor(D3DXCOLOR color) override;

protected:
	map<string, IComponent*> _componentList;
	int _hitPoint;

	Sprite* _sprite2;

	Sprite* _effect;
	Animation* _effectAnimation;
	StopWatch* _effectStopWatch;

	StopWatch* _hitStopWatch;
	bool _startHit;

	int _itemX;
	int _itemY;
};
#endif
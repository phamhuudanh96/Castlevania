#ifndef _BONE_H
#define _BONE_H

#include "..\FrameWork\define.h"
#include "BaseObject.h"
#include "..\Framework\IComponent.h"
#include "CollisionBody.h"
#include "../FrameWork/Animation.h"
#include "../Framework/StopWatch.h"
#include "QuadtreeNode.h"
#include <ctime>
#include "BigHeart.h"
#include "Heart.h"

#define BONE_MOVE_SPEED 70

class Bone : public BaseObject
{
public:
	Bone(int x, int y, int activeX);


	void init() override;
	void update(float deltatime) override;
	void draw(LPD3DXSPRITE, Viewport*) override;
	void release() override;

	void wasHit(int hitpoint);

	bool isDead();

protected:
	Animation* _animation;
	map<string, IComponent*> _componentList;
	int _activeXLeft;
	int _activeXRight;

	int _hitPoint;

	Sprite* _effect;
	Animation* _effectAnimation;
	StopWatch* _effectStopWatch;

	StopWatch* _hitStopWatch;
	bool _startHit;

};
#endif
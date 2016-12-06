﻿#ifndef __STAGE_21_H__
#define __STAGE_21_H__

#include "../Framework/Scene.h"
#include "../Object/BaseObject.h"
#include "../Framework/Text.h"
#include "../Tiles/TileMap.h"
#include "../Object/QuadtreeNode.h"
#include "../Object/Player.h"

using namespace std;


EVENT_RECEIVER
class PlayScene : public Scene
{
public:
	PlayScene();
	~PlayScene();

	bool init() override;
	void updateInput(float dt) override;
	void update(float dt) override;
	void draw(LPD3DXSPRITE spriteHandle) override;
	void release() override;

	void setViewport(Viewport* viewport);

	BaseObject* getObject(eID id);

	Player* getPlayer();
private:
	Text* _text;

	QuadTreeNode* _root;

	// Danh sách đối tượng nằm trong vùng active.
	// Mỗi vòng lặp sẽ được kiểm tra chỉnh sửa tại update, và sử dụng lại tại draw.
	vector<BaseObject*> _activeObject;

	TileMap* _tileMap;

	BaseObject* _player;

	void updateViewport(BaseObject* objTracker);

	bool checkEndGame();
};

#endif //
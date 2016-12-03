﻿/*
	HOW TO USE
	the Texture is used in Sprite and SpriteManager.
	you dont have to use Texture manually, just use Sprite or SpriteManager.
	IMPORTANT:
		if Texture instance is deleted by destructor, LPDIRECT3DTEXTURE9 is kept in memory => LEAK MEMORY
		call release before delete to avoid LEAK
*/
#ifndef __texture_H__
#define __texture_H__

#include "define.h"
#include "DeviceManager.h"
#include "Viewport.h"

GAMEUIT_FRAMEWORK
GAMEUIT_FRAMEWORK_BEGIN
	class Texture
	{
	public:
		Texture(void);
		~Texture(void);

		void release();


		HRESULT loadFromFile(LPD3DXSPRITE spriteHandle, LPWSTR filePath, D3DXCOLOR color = COLOR_WHITE, D3DXCOLOR colorkey = COLOR_KEY);


		void render(LPD3DXSPRITE spriteHandle, const RECT* rect, const GVector3* center, const GVector3* position);

		void render(LPD3DXSPRITE spriteHandle, RECT* srcRect, GVector2 position, GVector2 scale, float rotate, GVector2 origin, float zIndex = 0);

		void render(LPD3DXSPRITE spriteHandle, RECT* srcRect, Viewport viewport, GVector2 position, GVector2 scale, float rotate, GVector2 origin, float zIndex = 0);

		void setColor(D3DXCOLOR);
		D3DXCOLOR getColor();

		int getWidth();
		int getHeight();

	private:
		LPDIRECT3DTEXTURE9 _texture;
		D3DXIMAGE_INFO _imageInfo;
		D3DXCOLOR _color;
	};

	typedef Texture* pTexture;

	GAMEUIT_FRAMEWORK_END

#endif // !__texture_H__

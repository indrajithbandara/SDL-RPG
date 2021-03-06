#pragma once
#include "stdafx.h"
#include "SDL_Setup.h"
#include "Sprite.h"
class Tree
{
public:
	Tree(int x_passed, int y_passed, float *CameraX, float *CameraY, CSDL_Setup* csdl_setup);
	~Tree();

	void DrawCrown();
	void DrawTrunk();

	int GetX();
	int GetY();

	CSprite* GetCrown() {return Crown;}
	CSprite* GetTrunk() {return Trunk;}

private:
	int x, y;
	CSprite* Crown;
	CSprite* Trunk;

	
};


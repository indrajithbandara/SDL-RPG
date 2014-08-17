#include "stdafx.h"
#include <vld.h>
#include "GameLoop.h"

const string g_FONT_FILE = "Fonts/Minecraftia.ttf";

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	GameLoop*  mainGame = new GameLoop(640, 480);
	mainGame->Begin(false);

	delete mainGame;

	return 0;
}

#include "MainMenu.h"


CMainMenu::CMainMenu()
{

}

CMainMenu::CMainMenu(CSDL_Setup* passed_SDL_Setup, int *passed_MouseX, int *passed_MouseY, int passed_ScreenWidth, int passed_ScreenHeight, float *passed_CameraX, float *passed_CameraY)
{
	CameraX = passed_CameraX;
	CameraY = passed_CameraY;

	ScreenWidth = passed_ScreenWidth;
	ScreenHeight = passed_ScreenHeight;

	csdl_setup = passed_SDL_Setup;

	MouseX = passed_MouseX;
	MouseY = passed_MouseY;


	MainMenu = new CSprite(csdl_setup->GetRenderer(), "res/data/menu/mainmenu.gif", 0,0, ScreenWidth, ScreenHeight, CameraX, CameraY, CCollisionRect());

	PlayButton = new CSprite(csdl_setup->GetRenderer(), "res/data/menu/play-but.png", 230,140, 237, 74, CameraX, CameraY, CCollisionRect());
	PlayButton_Scroll = new CSprite(csdl_setup->GetRenderer(), "res/data/menu/play-but-scroll.png", 230,140, 237, 74, CameraX, CameraY, CCollisionRect());
	OptionButton = new CSprite(csdl_setup->GetRenderer(), "res/data/menu/option-but.png", 230,240, 237, 74, CameraX, CameraY, CCollisionRect());
	OptionButton_Scroll = new CSprite(csdl_setup->GetRenderer(), "res/data/menu/option-but-scroll.png", 230,240, 237, 74, CameraX, CameraY, CCollisionRect());
	AboutButton = new CSprite(csdl_setup->GetRenderer(), "res/data/menu/about-but.png", 230,340, 237, 74, CameraX, CameraY, CCollisionRect());
	AboutButton_Scroll = new CSprite(csdl_setup->GetRenderer(), "res/data/menu/about-but-scroll.png", 230,340, 237, 74, CameraX, CameraY, CCollisionRect());
	AboutPage = new CSprite(csdl_setup->GetRenderer(), "res/data/menu/about-page.png", 0,0, 640,480, CameraX, CameraY, CCollisionRect());
	AboutPage_Scroll = new CSprite(csdl_setup->GetRenderer(), "res/data/menu/about-page-hover.png", 0,0, 640, 480, CameraX, CameraY, CCollisionRect());

	/*timeCheck = SDL_GetTicks();Follow = false;*/
	/*distance = 0;
	stopAnimation = false;*/
	start = false;
}
CMainMenu::~CMainMenu()
{
	delete MainMenu;
	delete PlayButton;
	delete PlayButton_Scroll;
	delete OptionButton;
	delete OptionButton_Scroll;
	delete AboutButton;
	delete AboutButton_Scroll;
	delete AboutPage;
	delete AboutPage_Scroll;
}

void CMainMenu::Draw()
{
	MainMenu->Draw();
	PlayButton->Draw();
	OptionButton->Draw();
	AboutButton->Draw();
	cout << "Mouse X = " << *MouseX;
	cout << "\tMouse Y = " << *MouseY;
	system("cls");
}

bool CMainMenu::AboutMenu()
{
	cout << "Mouse X = " << *MouseX;
	cout << "\tMouse Y = " << *MouseY;
	system("cls");
	AboutPage->Draw();
	start = false;
		if (csdl_setup->GetMainEvent()->type == SDL_MOUSEMOTION)
		{
			if (*MouseX > 110 && *MouseX <= 540 && *MouseY > 310 && *MouseY <= 360)
			{
				AboutPage_Scroll->Draw();
				//get anim for mouseclick, run gameloop
				cout << "You have scrolled over the return to menu button!" << endl;
				/*system("pause");*/
			}
		}
		if (csdl_setup->GetMainEvent()->type == SDL_MOUSEBUTTONDOWN)
		{
			if (csdl_setup->GetMainEvent()->button.button == SDL_BUTTON_LEFT)
			{
				if (*MouseX > 110 && *MouseX <= 540 && *MouseY > 310 && *MouseY <= 360)
				{
					AboutPage_Scroll->Draw();
					//get anim for mouseclick, run gameloop
					cout << "You have clicked the return to menu button!" << endl;
					start = true;
					return start;
				}
			}
		}
	return start;
}

int CMainMenu::GetButtonClick()
{
	//for mouse motion
	/*do
	{*/

	//Playbutton code for scroll
		if (csdl_setup->GetMainEvent()->type == SDL_MOUSEMOTION)
		{
			if (*MouseX > 230 && *MouseX <= 400 && *MouseY > 140 && *MouseY <= 214)
			{
				PlayButton_Scroll->Draw();
				//get anim for mouseclick, run gameloop
				cout << "You have scrolled over the start game button!" << endl;
				/*system("pause");*/
			}
		}
		//Playbutton code for clicking
		if (csdl_setup->GetMainEvent()->type == SDL_MOUSEBUTTONDOWN)
		{
			if (csdl_setup->GetMainEvent()->button.button == SDL_BUTTON_LEFT)
			{
				if (*MouseX > 230 && *MouseX <= 466 && *MouseY > 140 && *MouseY <= 214)
				{
					PlayButton_Scroll->Draw();
					//get anim for mouseclick, run gameloop
					cout << "You have clicked the start game button!" << endl;
					return 1;
				}
			}
		}

		if (csdl_setup->GetMainEvent()->type == SDL_MOUSEMOTION)
		{
			if (*MouseX > 230 && *MouseX <= 460 && *MouseY > 240 && *MouseY <= 340)
			{
				OptionButton_Scroll->Draw();
				//get anim for mouseclick, run gameloop
				cout << "You have scrolled over the option button!" << endl;
				/*system("pause");*/
			}
		}
		if (csdl_setup->GetMainEvent()->type == SDL_MOUSEBUTTONDOWN)
		{
			if (csdl_setup->GetMainEvent()->button.button == SDL_BUTTON_LEFT)
			{
				if (*MouseX > 230 && *MouseX <= 466 && *MouseY > 240 && *MouseY <= 340)
				{
					OptionButton_Scroll->Draw();
					//get anim for mouseclick, run gameloop
					cout << "You have clicked the option button!" << endl;
					return 2;
				}
			}
		}

		if (csdl_setup->GetMainEvent()->type == SDL_MOUSEMOTION)
		{
			if (*MouseX > 230 && *MouseX <= 400 && *MouseY > 340 && *MouseY <= 440)
			{
				AboutButton_Scroll->Draw();
				//get anim for mouseclick, run gameloop
				cout << "You have scrolled over the about button!" << endl;
				/*system("pause");*/
			}
		}
		if (csdl_setup->GetMainEvent()->type == SDL_MOUSEBUTTONDOWN)
		{
			if (csdl_setup->GetMainEvent()->button.button == SDL_BUTTON_LEFT)
			{
				if (*MouseX > 230 && *MouseX <= 466 && *MouseY > 320 && *MouseY <= 420)
				{
					AboutButton_Scroll->Draw();
					//get anim for mouseclick, run gameloop
					cout << "You have clicked the about button!" << endl;
					return 3;
				}
			}
		}

		return 0;
	} /*while (start==false);*/
	



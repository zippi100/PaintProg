#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <ctime>

struct splatStat
{
	sf::Sprite sp;
	int x;
	int y;
};
struct craterStat
{
	sf::Sprite sp;
	int x;
	int y;
};


class VisualObjectManager
{
public:
	bool showTools;
	//images
	int splatCount;
	int craterCount;
	sf::Texture back;
	sf::Sprite backGround;

	sf::Texture red;
	sf::Sprite redColor;

	sf::Texture blue;
	sf::Sprite blueColor;

	sf::Texture green;
	sf::Sprite greenColor;


	sf::Texture fileDropDownBaseTexture;
	sf::Texture fileDropDownFileSelectTexture;
	sf::Texture fileDropDownOptionSelectTexture;
	sf::Texture fileDropDownSaveSelectTexture;
	sf::Texture fileDropDownSaveAsSelectTexture;
	sf::Texture pencilTexture;
	sf::Texture colorPaletteTexture;
	sf::Texture lightSaberTexture;
	sf::Texture meteorTexture;
	sf::Texture alienTexture;
	sf::Texture toolBarClosed;
	sf::Texture toolBarOpen;
	sf::Texture splatTexture;
	sf::Texture craterTexture;


	sf::Sprite toolBar;
	sf::Sprite splat;
	sf::Sprite toolBarOpened;
	sf::Sprite fileDropDownBase;
	sf::Sprite fileDropDownFileSelect;
	sf::Sprite fileDropDownOptionSelect;
	sf::Sprite fileDropDownSaveSelect;
	sf::Sprite fileDropDownSaveAsSelect;
	sf::Sprite pencil;
	sf::Sprite colorPalette;
	sf::Sprite lightSaber;
	sf::Sprite meteor;
	sf::Sprite alien;
	sf::Sprite crater;
	bool alienOnTheMove;
	VisualObjectManager();
	void alienTerror(bool clicked);
	~VisualObjectManager();
	splatStat * splatContainer = new splatStat[7000];
	craterStat * craterContainer = new craterStat[7000];
	void callMeteor();
	sf::Clock clock;
};


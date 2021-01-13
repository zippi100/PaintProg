#include "stdafx.h"
#include "VisualObjectManager.h"
#include <iostream>
using namespace std;

VisualObjectManager::VisualObjectManager()
{
	back.loadFromFile("image.png");
	red.loadFromFile("red.png");
	blue.loadFromFile("blue.png");
	green.loadFromFile("green.png");
	fileDropDownBaseTexture.loadFromFile("fileDropDownBase.png");
	fileDropDownFileSelectTexture.loadFromFile("fileDropDownFileSelect.png");
	fileDropDownOptionSelectTexture.loadFromFile("fileDropDownOptionSelect.png");
	fileDropDownSaveSelectTexture.loadFromFile("fileDropDownSaveSelect.png");
	fileDropDownSaveAsSelectTexture.loadFromFile("fileDropDownSaveAsSelect.png");
	pencilTexture.loadFromFile("pencil.png");
	colorPaletteTexture.loadFromFile("Colors.png");
	alienTexture.loadFromFile("alien.png");
	lightSaberTexture.loadFromFile("lightsaber.png");
	meteorTexture.loadFromFile("asteroid.png");
	toolBarOpen.loadFromFile("ToolsExpanded.png");
	toolBarClosed.loadFromFile("ToolsClosed.png");
	splatTexture.loadFromFile("splat.png");
	craterTexture.loadFromFile("crater.png");
	

	//applies textures to sprites
	toolBar.setTexture(toolBarClosed);
	backGround.setTexture(back);
	redColor.setTexture(red);
	blueColor.setTexture(green);
	greenColor.setTexture(blue);
	fileDropDownBase.setTexture(fileDropDownBaseTexture);
	fileDropDownFileSelect.setTexture(fileDropDownFileSelectTexture);
	fileDropDownOptionSelect.setTexture(fileDropDownOptionSelectTexture);
	fileDropDownSaveSelect.setTexture(fileDropDownSaveSelectTexture);
	fileDropDownSaveAsSelect.setTexture(fileDropDownSaveAsSelectTexture);
	pencil.setTexture(pencilTexture);
	colorPalette.setTexture(colorPaletteTexture);
	alien.setTexture(alienTexture);
	lightSaber.setTexture(lightSaberTexture);
	meteor.setTexture(meteorTexture);
	toolBarOpened.setTexture(toolBarOpen);
	crater.setTexture(craterTexture);

	craterCount = 0;
	//set position
	toolBar.setPosition(500, 0);
	toolBarOpened.setPosition(500, 0);
	redColor.setPosition(200, 0);
	blueColor.setPosition(250, 0);
	greenColor.setPosition(300, 0);
	fileDropDownBase.setPosition(0, 0);
	fileDropDownFileSelect.setPosition(0, 0);
	fileDropDownOptionSelect.setPosition(0, 0);
	fileDropDownSaveAsSelect.setPosition(0, 0);
	fileDropDownSaveSelect.setPosition(0, 0);
	pencil.setPosition(780, 0);
	colorPalette.setPosition(600, 0);
	alien.setPosition(700, 0);
	lightSaber.setPosition(600, 0);
	meteor.setPosition(650, 0);
	alienOnTheMove = false;
	showTools = false;
	clock.restart();
}


VisualObjectManager::~VisualObjectManager()
{
}


void VisualObjectManager::alienTerror(bool clicked)
{
	srand(time(NULL));
	static int x = 700;
	static int y = 0;
	int random2;
	int random;

	if (clock.getElapsedTime().asSeconds() > .1)
	{
		
		clock.restart();
		random = rand() % 6 + 1;
	}
	random2 = rand() % 5 + 1;
	if (random == 1)
	{
		x += 25;
		y += 40;
		alien.move(x, y);
	}
	else if (random == 2)
	{
		x -= 25;
		y += 40;
		alien.move(x, y);
	}
	else if (random == 3)
	{
		x += 25;
		y -= 40;
		alien.move(x, y);
	}
	else if (random == 4)
	{
		x -= 25;
		y -= 40;
		alien.move(x, y);
	}
	else if (random == 5)
	{
		x -= 15;
	}
	else if (random == 6)
	{
		x += 15;
	}

	if (random2 == 5)
	{
		splatContainer[splatCount].sp.setTexture(splatTexture);
		splatContainer[splatCount].sp.setPosition(x, y);
		splatCount++;
	}
	//boundary
	if (x < 0) x = 0;
	if (y < 0) y = 0;
	if (y > 690) y = 690;
	if (x > 1050) x = 1050;

	if (clicked)
	{
		alien.setPosition(x, y);
	}

}

void VisualObjectManager::callMeteor()
{
	srand(time(NULL));
	int random1;
	int random2;
	random1 = rand() % 1000 + 1;
	random2 = rand() % 1000 + 1;
	craterContainer[craterCount].sp.setTexture(craterTexture);
	craterContainer[craterCount].sp.setPosition(random1, random2);
	craterCount++;
}
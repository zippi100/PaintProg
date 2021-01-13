#pragma once
#include "VisualObjectManager.h"
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <string>



struct colorGrid
{
	int x;
	int y;
	sf::Color color;
};

class mainScreen
{
public:
	VisualObjectManager VisualObjManager;
	mainScreen MainScreen();
	void mainCall();
	void updateArt(int a, int b, sf::Color);
	sf::RenderWindow window;
	int currentState;
	colorGrid * art = new colorGrid[700000];
	int pixelCount;
	bool drawSpace;
	bool lightSaberOn;
	sf::Color currentColor;



};



#include "stdafx.h"
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <sstream>
#include "mainScreen.h"
#include <iostream>
#pragma warning(disable: 4996)
using namespace std;




mainScreen mainScreen::MainScreen()
{
	currentState = 0;
	pixelCount = 0;
	currentColor = sf::Color::Black;
	drawSpace = false;
	lightSaberOn = false;
}


void mainScreen::updateArt(int a, int b, sf::Color col)
{	
	bool dupe = false;
	//check to see dupes
	for (int i = 0; i < pixelCount; i++)
	{
		if (art[i].x == a && art[i].y == b)
		{
			dupe = true;
			art[i].x = a;
			art[i].y = b;
			art[i].color = currentColor;
		}
		
	}
	if (!dupe)
	{
		art[pixelCount].x = a;
		art[pixelCount].y = b;
		art[pixelCount].color = col;
		pixelCount++;
	}
}
void mainScreen::mainCall()
{
	static sf::RenderWindow window(sf::VideoMode(1100, 750), "Paint");
	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		sf::CircleShape shapeOnMouse(12.0f);
		sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
		shapeOnMouse.setFillColor(sf::Color::Black);
		ostringstream convert;   // stream used for the conversion
		ostringstream convert2;
		convert << mousePos.x;      // insert the textual representation of 'Number' in the characters in the stream
		convert << mousePos.y;      // insert the textual representation of 'Number' in the characters in the stream


		sf::Font font;
		font.loadFromFile("times.ttf");
		string mouse1pos = convert.str();
		string mouse2pos = convert2.str();

		sf::Text mousePosText;
		mousePosText.setColor(sf::Color::Black);
		mousePosText.setCharacterSize(30);
		mousePosText.setPosition(940, 670);
		mousePosText.setFont(font);
		mousePosText.setString("(" + mouse1pos + mouse2pos + ")");
		mousePosText.setStyle(sf::Text::Bold | sf::Text::Underlined);
		//initializes textures
		
		sf::FloatRect toolBarBounds = VisualObjManager.toolBar.getGlobalBounds();
		sf::FloatRect toolBarOpenedBounds = VisualObjManager.toolBarOpened.getGlobalBounds();
		sf::FloatRect lightSaberBounds = VisualObjManager.lightSaber.getGlobalBounds();
		sf::FloatRect meteorBounds = VisualObjManager.meteor.getGlobalBounds();




		switch (currentState)
		{

			//loading and what not
		case 0:

			window.draw(VisualObjManager.backGround);
			window.draw(VisualObjManager.redColor);
			window.draw(VisualObjManager.blueColor);
			window.draw(VisualObjManager.greenColor);
			currentState = 1;
			sf::Event event;
			break;
		case 1:
			//grabs event
			window.pollEvent(event);

			//handles a way to close the screen
			if (event.type == sf::Event::Closed)  window.close();

			//tells program whats drawable
			if (toolBarBounds.contains(mousePos) || toolBarOpenedBounds.contains(mousePos))
			{
				drawSpace = false;
			}
			else drawSpace = true;


			//makes sure you cant draw on objects
			if (drawSpace)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (mousePos.y > 23)
					{
						if (lightSaberOn)
						{

							updateArt(mousePos.x-1, mousePos.y, sf::Color::White);
							updateArt(mousePos.x, mousePos.y - 1, sf::Color::White);
							updateArt(mousePos.x + 1, mousePos.y, sf::Color::White);
							updateArt(mousePos.x, mousePos.y + 1, sf::Color::White);
							updateArt(mousePos.x, mousePos.y, currentColor);

						}
						else updateArt(mousePos.x, mousePos.y, currentColor);
					}
				}
			}

			if (lightSaberBounds.contains(mousePos))
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					lightSaberOn = true;
				}
			}
			else if(meteorBounds.contains(mousePos))
			{
				VisualObjManager.callMeteor();
			}
		


				//handles the drawing
				if (event.type == sf::Event::MouseButtonReleased)
				{
					if (mousePos.x > 600 && mousePos.x < 630 && mousePos.y < 23) currentState = 3;

				}
			
			window.clear();
			window.draw(VisualObjManager.backGround);
			window.draw(mousePosText);

			window.draw(VisualObjManager.toolBar);

			//handles tool bar showing or not
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (toolBarBounds.contains(mousePos))
				{
					if (VisualObjManager.showTools == true)VisualObjManager.showTools = false;
					else VisualObjManager.showTools = true;
				}
			}
			window.draw(VisualObjManager.colorPalette);
			

	
			

			


				//drawArt
				for (int i = 0; i < pixelCount; i++)
				{
					sf::CircleShape shapeOnMouse(12.f);
					shapeOnMouse.setFillColor(art[i].color);
					shapeOnMouse.setPosition(art[i].x, art[i].y);
					window.draw(shapeOnMouse);
				}

				//draw splats
				for (int i = 0; i < VisualObjManager.splatCount; i++)
				{

					window.draw(VisualObjManager.splatContainer[i].sp);
				}

				//draw craters
				for (int i = 0; i < VisualObjManager.craterCount; i++)
				{
	
					window.draw(VisualObjManager.craterContainer[i].sp);
				}

				if (VisualObjManager.showTools == true)
				{
					window.draw(VisualObjManager.toolBarOpened);
					window.draw(VisualObjManager.alien);
					window.draw(VisualObjManager.lightSaber);
					window.draw(VisualObjManager.meteor);
					window.draw(VisualObjManager.pencil);
				}




				//paint was clicked
				if (event.type == sf::Event::MouseButtonReleased)
				{
					if (mousePos.x < 55 && mousePos.y < 20) currentState = 2;

				}
				//Alien was clicked    
				if (event.type == sf::Event::MouseButtonReleased)
				{
					if (mousePos.x > 700 && mousePos.x < 750 && mousePos.y < 20)VisualObjManager.alienOnTheMove = true; 

				}

				//handles alien moving event
				if (VisualObjManager.alienOnTheMove)
				{
					VisualObjManager.alienTerror(true);
					window.draw(VisualObjManager.alien);
				}

			window.display();
			break;
			
			//file menu
		case 2:
			window.pollEvent(event);
			window.clear();
			window.draw(VisualObjManager.backGround);
			window.draw(VisualObjManager.pencil);
			window.draw(VisualObjManager.colorPalette);



			//drawArt
			for (int i = 0; i < pixelCount; i++)
			{
				sf::CircleShape shapeOnMouse(12.f);
				shapeOnMouse.setFillColor(art[i].color);
				shapeOnMouse.setPosition(art[i].x, art[i].y);
				window.draw(shapeOnMouse);
			}





		if (mousePos.x > 217 || mousePos.y > 200) currentState = 1;






			window.draw(VisualObjManager.fileDropDownBase);
			window.draw(mousePosText);
			window.display();





			break;

			//picking colors
		case 3:
			window.pollEvent(event);

			if (event.type == sf::Event::Closed)  window.close();

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (mousePos.y > 23) updateArt(mousePos.x, mousePos.y, currentColor);
			}
			if (event.type == sf::Event::MouseButtonReleased)
			{
				if (mousePos.x > 200 && mousePos.x < 250 && mousePos.y < 50) currentColor = sf::Color::Red;
				if (mousePos.x > 250 && mousePos.x < 300 && mousePos.y < 50) currentColor = sf::Color::Green;
				if (mousePos.x > 300 && mousePos.x < 350 && mousePos.y < 50) currentColor = sf::Color::Blue;
			}

			//closes paint and goes back to state 1
			if (mousePos.y > 49) currentState = 1;

			window.clear();
			window.draw(VisualObjManager.backGround);
			window.draw(mousePosText);
			window.draw(VisualObjManager.pencil);
			window.draw(VisualObjManager.colorPalette);



			//drawArt
			for (int i = 0; i < pixelCount; i++)
			{
				sf::CircleShape shapeOnMouse(12.f);
				shapeOnMouse.setFillColor(art[i].color);
				shapeOnMouse.setPosition(art[i].x, art[i].y);
				window.draw(shapeOnMouse);
			}



			if (event.type == sf::Event::MouseButtonReleased)
			{
				if (mousePos.x < 55 && mousePos.y < 20) currentState = 2;

			}
			window.draw(VisualObjManager.redColor);
			window.draw(VisualObjManager.blueColor);
			window.draw(VisualObjManager.greenColor);

			window.display();
			break;

		}

	}
}


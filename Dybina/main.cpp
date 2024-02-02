#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>


#include "PhysicModel.h"
#include "Player.h"
#include "MapStaticObjects.h"

#include "Engine.h"


int main()
{   
   

    sf::Texture human_texture;
    human_texture.loadFromFile("C:\\Users\\ranja\\source\\repos\\Dybina\\Dybina\\user.png");


    sf::Texture wallTexture;
    wallTexture.loadFromFile("C:\\Users\\ranja\\source\\repos\\Dybina\\Dybina\\Wall.jpg");

    //EnginePlayersObjects
    Engine::AllPlayerObjects allPlayersObjects;

    //Engine All static objects
    Engine::AllStaticObjects allStaticObjects;


    //createYourPlayer
    PlayersM::StandartPlayer yourPlayer(human_texture,10.0,50.0);
    allPlayersObjects.addPlayerToVector(&yourPlayer);
    
    //createWall
    MapObjects::Wall wall(wallTexture, 100, 50);
    allStaticObjects.addStaticObjectToVector(&wall);


    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            yourPlayer.setWhereGo("left");
            if (allStaticObjects.checkCanPlayerMove(yourPlayer))
            {
                
            }
            else 
            {
                yourPlayer.moveLeft();
            }
            
            
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {   
            yourPlayer.setWhereGo("right");
            if (allStaticObjects.checkCanPlayerMove(yourPlayer))
            {
                
                
            }
            else
            {
                yourPlayer.moveRight();
            }
            
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {   
            yourPlayer.setWhereGo("up");
            if (allStaticObjects.checkCanPlayerMove(yourPlayer))
            {
                
            }
            else
            {
                yourPlayer.moveUp();
            }
            
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {   
            yourPlayer.setWhereGo("down");
            if (allStaticObjects.checkCanPlayerMove(yourPlayer))
            {
                
            }
            else
            {
                yourPlayer.moveDown();
            }
            
        }


        window.clear(sf::Color::Black);

        //Draw all players
        allPlayersObjects.drawAllPlayers(window);

        //Draw all static objects
        allStaticObjects.drawAllStaticObjects(window);
        
        window.draw(yourPlayer.getPhysicModel().getPhysicModel());
        
        window.display();
    }

    return 0;
}
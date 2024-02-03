#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>

#include "PhysicModel.h"


#include "Player.h"
#include "Bullet.h"
#include "MapStaticObjects.h"

#include "Engine.h"

#include "Guns.h"


int main()
{   
   

    sf::Texture human_texture;
    human_texture.loadFromFile("C:\\Users\\croune\\source\\repos\\Dybina\\Dybina\\user.png");


    sf::Texture wallTexture;
    wallTexture.loadFromFile("C:\\Users\\croune\\source\\repos\\Dybina\\Dybina\\Wall.jpg");

    sf::Texture standartBulletTexture;
    standartBulletTexture.loadFromFile("C:\\Users\\croune\\source\\repos\\Dybina\\Dybina\\StandartBullet.png");
    
    //EnginePlayersObjects
    Engine::AllPlayerObjects allPlayersObjects;

    //Engine All static objects
    Engine::AllStaticObjects allStaticObjects;

    //Engine All Bullets
    Engine::AllBullets allBullets;


    //createYourPlayer
    PlayersM::StandartPlayer yourPlayer(human_texture,100.0,800.0);
    allPlayersObjects.addPlayerToVector(&yourPlayer);
    
    //createWall
    MapObjects::Wall wall(wallTexture, 100, 900);
    allStaticObjects.addStaticObjectToVector(&wall);


    MapObjects::Wall wall1(wallTexture, 1000, 900);
    allStaticObjects.addStaticObjectToVector(&wall1);


    MapObjects::Wall wall2(wallTexture, 100, 500);
    allStaticObjects.addStaticObjectToVector(&wall2);


    sf::RenderWindow window(sf::VideoMode(1920, 1080), "My window");

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
            yourPlayer.jumpStatus = true;
            
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {   
            //yourPlayer.setWhereGo("down");
            //if (allStaticObjects.checkCanPlayerMove(yourPlayer))
            //{
                
            //}
            //else
            //{
                //yourPlayer.moveDown();
            //}
            
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) 
        {   
            
            
            Bullets::StandartBullet* n_bul = new Bullets::StandartBullet(standartBulletTexture, yourPlayer.getPosition().x, yourPlayer.getPosition().y,yourPlayer.where_bullet_go);
            allBullets.addBulletObjectToVector(n_bul);
        }


        yourPlayer.setWhereGo("down");
        if (allStaticObjects.checkCanPlayerMove(yourPlayer))
        {

        }
        else
        {
            yourPlayer.moveDown();
        }

        //check all moves jump and other

        
        
        yourPlayer.setWhereGo("up");
        yourPlayer.jump(allStaticObjects.checkCanPlayerMove(yourPlayer));
            
        

        window.clear(sf::Color::Black);

        //Draw all players
        allPlayersObjects.drawAllPlayers(window);

        //Draw all static objects
        allStaticObjects.drawAllStaticObjects(window);

        //Draw all bullets
        allBullets.drawAllBulletsObjects(window);

        //move all Bullets
        allBullets.moveAllBullets();

        allBullets.checkOutSideBullets(allStaticObjects);
        
        //window.draw(yourPlayer.getPhysicModel().getPhysicModel());
        
        window.display();
    }

    return 0;
}
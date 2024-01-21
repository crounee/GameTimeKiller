#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <vector>


#include "EngineObjects.h"
#include "Player.h"

int main()
{
    sf::Texture human_texture;
    human_texture.loadFromFile("C:\\Users\\croune\\source\\repos\\Dybina\\Dybina\\user.png");


    EngineObjects::LiveUnites<Player::Player> player_unites;
    
    Player::Your_player your_player(human_texture);

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
            your_player.go_left();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            your_player.go_right();
        }
        
        window.clear(sf::Color::Black);

        window.draw(your_player.human_model);
        
        window.display();
    }

    return 0;
}
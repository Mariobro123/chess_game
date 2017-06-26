#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace std;


int main()
{

    sf::RenderWindow okno(sf::VideoMode(800,800),"Szachy");
    sf::Event wydarzenie;
    sf::Vector2i pozycjaMyszy;
//    sf::Vector2f pozycjaMyszyNaScenie;

    sf::Texture tekstura, cos;
    tekstura.loadFromFile( "images/szachownica.jpg" );
    cos.loadFromFile("images/cos.png");

    sf::Sprite szachownica, gunwo;
    szachownica.setTexture(tekstura);
    gunwo.setTexture(cos);

    while(okno.isOpen())
    {
        while(okno.pollEvent(wydarzenie))
        {
            if(wydarzenie.type == sf::Event::KeyPressed && wydarzenie.key.code ==
               sf::Keyboard::Escape)
                okno.close();
        }

        okno.draw(szachownica);

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            pozycjaMyszy = sf::Mouse::getPosition( okno );
//            pozycjaMyszyNaScenie = okno.convertCoords( pozycjaMyszy )

        }
//        okno.draw(gunwo);
            gunwo.setPosition(pozycjaMyszy.x, pozycjaMyszy.y);

        okno.display();

    }

return 0;

}

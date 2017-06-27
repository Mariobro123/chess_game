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

    sf::Texture tekstura, zaznaPola;
    tekstura.loadFromFile( "images/szachownica.jpg" );
    zaznaPola.loadFromFile("images/zaznaPola.png");

    sf::Sprite szachownica, zaznaczeniePola;
    szachownica.setTexture(tekstura);
    zaznaczeniePola.setTexture(zaznaPola);
    bool czyPoleZaznaczone = false;
    int indeksPionka;

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
            pozycjaMyszy.x = (pozycjaMyszy.x / 100) * 100;
            pozycjaMyszy.y = (pozycjaMyszy.y / 100) * 100;
            czyPoleZaznaczone = true;

        }
        if (czyPoleZaznaczone == true)
        {
            okno.draw(zaznaczeniePola);
        }

        zaznaczeniePola.setPosition(pozycjaMyszy.x, pozycjaMyszy.y);

        okno.display();

    }

return 0;

}

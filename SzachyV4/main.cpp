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

    sf::Texture tekstura, zaznaPola, bierki;

    tekstura.loadFromFile( "images/szachownica.jpg" );
    zaznaPola.loadFromFile("images/zaznaPola.png");
    bierki.loadFromFile("images/bierki.png");

    sf::Sprite szachownica, zaznaczeniePola, pionekb, wiezab, konb, goniecb, hetmanb, krolb, pionekc, wiezac, konc, goniecc, hetmanc, krolc;

    szachownica.setTexture(tekstura);
    zaznaczeniePola.setTexture(zaznaPola);

    pionekc.setTexture(bierki);
    pionekc.setTextureRect(sf::IntRect(500, 100, 100, 100));

    pionekb.setTexture(bierki);
    pionekb.setTextureRect(sf::IntRect(500, 0, 100, 100));

    wiezac.setTexture(bierki);
    wiezac.setTextureRect(sf::IntRect(0, 100, 100, 100));

    wiezab.setTexture(bierki);
    wiezab.setTextureRect(sf::IntRect(0, 0, 100, 100));

    konc.setTexture(bierki);
    konc.setTextureRect(sf::IntRect(100, 100, 100, 100));

    konb.setTexture(bierki);
    konb.setTextureRect(sf::IntRect(100, 0, 100, 100));

    goniecc.setTexture(bierki);
    goniecc.setTextureRect(sf::IntRect(200, 100, 100, 100));

    goniecb.setTexture(bierki);
    goniecb.setTextureRect(sf::IntRect(200, 0, 100, 100));

    hetmanc.setTexture(bierki);
    hetmanc.setTextureRect(sf::IntRect(300, 100, 100, 100));

    hetmanb.setTexture(bierki);
    hetmanb.setTextureRect(sf::IntRect(300, 0, 100, 100));

    krolc.setTexture(bierki);
    krolc.setTextureRect(sf::IntRect(400, 100, 100, 100));

    krolb.setTexture(bierki);
    krolb.setTextureRect(sf::IntRect(400, 0, 100, 100));

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

        for (int i = 0; i < 8; i++)
            {
                okno.draw(pionekc);
                pionekc.setPosition(100*i, 100);
            }

        for (int i = 0; i < 8; i++)
            {
                okno.draw(pionekb);
                pionekb.setPosition(100*i, 600);
            }

            okno.draw(wiezac);
            wiezac.setPosition(0,0);
            okno.draw(wiezac);
            wiezac.setPosition(700,0);

            okno.draw(wiezab);
            wiezab.setPosition(0,700);
            okno.draw(wiezab);
            wiezab.setPosition(700,700);

            okno.draw(konc);
            konc.setPosition(100,0);
            okno.draw(konc);
            konc.setPosition(600,0);

            okno.draw(konb);
            konb.setPosition(100,700);
            okno.draw(konb);
            konb.setPosition(600,700);

            okno.draw(goniecc);
            goniecc.setPosition(200,0);
            okno.draw(goniecc);
            goniecc.setPosition(500,0);

            okno.draw(goniecb);
            goniecb.setPosition(200,700);
            okno.draw(goniecb);
            goniecb.setPosition(500,700);

            okno.draw(hetmanc);
            hetmanc.setPosition(300,000);
            okno.draw(hetmanb);
            hetmanb.setPosition(300,700);

            okno.draw(krolc);
            krolc.setPosition(400,000);
            okno.draw(krolb);
            krolb.setPosition(400,700);


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

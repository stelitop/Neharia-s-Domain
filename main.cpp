#include<iostream>
#include<SFML/Graphics.hpp>
#include<fstream>
using namespace std;
using namespace sf;
RenderWindow window(VideoMode(1280,1024), "Game" , Style::Fullscreen );

#include"loadstuff.h"

weapon ListWeapons[1001];

int main()
{
    ListWeapons[1].loadFromFile("items/weapons/starting_sword.wpn");
    cout<<ListWeapons[1].attributes.atk<<endl;
    bool update=true;
    while (window.isOpen())
    {
        if (update==true)
        {
            update=false;
            window.clear();


            window.display();
        }

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::KeyPressed)
            {
                if (Keyboard::isKeyPressed(Keyboard::Escape))
                {
                    window.close();
                }
            }
        }
    }
    return 0;
}

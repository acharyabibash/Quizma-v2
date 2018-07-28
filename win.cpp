/*#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "QUIZMA");
    sf::CircleShape circleRed(50);
    sf::CircleShape circleGreen(30);
    sf::CircleShape circleBlue(20);
    sf::CircleShape circleGray(30);
    sf::CircleShape circlen(50);
    
    circleRed.setFillColor(sf::Color(255, 0, 0));
    circleGreen.setFillColor(sf::Color(0, 255, 0));
    circleBlue.setFillColor(sf::Color(0, 0, 255));
    circleGray.setFillColor(sf::Color(100,100,100));
 circlen.setFillColor(sf::Color(150,100,50));
   
    float xRed=100;
    float yRed=100;
    
    float xGreen = 250;
    float yGreen = 100;
    
    
    float xBlue = 400;
    float yBlue = 100;
    
    float xGray=550;
    float yGray=100;
 
    float xn=700;
    float yn=100;
  
    circleRed.setPosition(xRed, yRed);
         
   
    
    circleGreen.setPosition(xGreen, yGreen);
 
  
  
    circleBlue.setPosition(xBlue, yBlue);
    
    circleGray.setPosition(xGray, yGray);
 circlen.setPosition(xn, yn);
    
    while (window.isOpen())
    {
      
        sf::Event event;
        while (window.pollEvent(event))
        {
            
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
   //     xGreen = xGreen + 0.01;
        yGreen=yGreen+0.5;

if (yGreen>800)
yGreen=yGreen*(-1);
 

//xBlue=xBlue+0.2;
yBlue = yBlue + 0.5;

if (yBlue>800)
yBlue =yBlue *(-1);

//xRed = xRed + 0.2;
 yRed = yRed+0.5;
 
 if (yRed>800)
yRed=yRed*(-1);
 
// xGray = xGray + 0.2;
 yGray=yGray+0.5;
 
 if (yGray>800)
yGray =yGray*(-1);
 
 yn=yn+0.5;
 
 if (yn>800)
yn=yn*(-1);
 
circleGreen.setPosition(xGreen, yGreen);

circleRed.setPosition(xRed, yRed);


circleBlue.setPosition(xBlue, yBlue);
     
  circleGray.setPosition(xGray, yGray);
      
    circlen.setPosition(xn, yn);     
        window.draw(circleRed);
        window.draw(circleGreen);
        window.draw(circleBlue);
         window.draw(circleGray);
                 window.draw(circlen);
        
        window.display();
 
    }
 
    return 0;
}
*/

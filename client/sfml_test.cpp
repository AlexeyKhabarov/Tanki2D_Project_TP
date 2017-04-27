#include <SFML/Graphics.hpp>

// using namespase sf;
int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML tank!");
    
    sf::Image tank;
    tank.loadFromFile("image/tank_top.png");

    sf::Texture texture;
    texture.loadFromImage(tank);
    texture.setSmooth(true);

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sf::FloatRect spriteSize = sprite.getGlobalBounds();
    sprite.setOrigin(spriteSize.width/2.0, spriteSize.height/2.0);
    sprite.setScale(0.2,0.2);
    sprite.setPosition(200, 200);
    
    

    while (window.isOpen()) {
        sf::Event event;

        // Flags for key pressed
        bool upFlag = false;
        bool downFlag = false;
        bool leftFlag = false;
        bool rightFlag = false;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                // If escape is pressed, close the application
                    case  sf::Keyboard::Escape : 
                        window.close(); 
                        break;
                // Process the up, down, left and right keys
                    case sf::Keyboard::Up : 
                        upFlag=true; 
                        break;
                    case sf::Keyboard::Down : 
                        downFlag=true; 
                        break;
                    case sf::Keyboard::Left : 
                        leftFlag=true; 
                        break;
                    case sf::Keyboard::Right : 
                        rightFlag=true; 
                        break;
                    default : break;
                }
            }

            // If a key is released
            if (event.type == sf::Event::KeyReleased) {
                switch (event.key.code) {
                // Process the up, down, left and right keys
                    case sf::Keyboard::Up : 
                        upFlag=false; 
                        break;
                    case sf::Keyboard::Down: 
                        downFlag=false; 
                        break;
                    case sf::Keyboard::Left: 
                        leftFlag=false; 
                        break;
                    case sf::Keyboard::Right: 
                        rightFlag=false; 
                        break;
                    default : break;
                }
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            if (sprite.getRotation() != 270) {
                sprite.setRotation(270);
            } 
            sprite.move(-0.1,0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

            if (sprite.getRotation() != 90) {
                sprite.setRotation(90);
            } 
            sprite.move(0.1,0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

            if (sprite.getRotation() != 0) {
                sprite.setRotation(0);
            } 
            sprite.move(0,-0.1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {

            if (sprite.getRotation() != 180) {
                sprite.setRotation(180);
            } 
            sprite.move(0,0.1);
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }
    return 0;
}
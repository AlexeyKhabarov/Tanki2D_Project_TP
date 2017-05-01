#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <iostream>

typedef struct{
    float X;
    float Y;
} Point;

class Tank{
public:
    int HP;
    Point point;

    Tank(int health, float x, float y): HP(health) {
        point.X = x;
        point.Y = y;
    }
};

int main(int argc, char* argv[]){

    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML tank!");
    
    sf::Image tank;
    tank.loadFromFile("../image/tank_top.png");

    sf::Texture texture;
    texture.loadFromImage(tank);
    texture.setSmooth(true);

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sf::FloatRect spriteSize = sprite.getGlobalBounds();
    sprite.setOrigin(spriteSize.width/2.0, spriteSize.height/2.0);
    sprite.setScale(0.2,0.2);
     
    Tank player = Tank(0, 0, 0);

    //sf::IpAddress ip = sf::IpAddress::getLocalAddress();

    sf::TcpSocket socket, server_socket;
    sf::TcpListener listener;
    sf::Packet out_packet, in_packet;

    std::string server_ip;
    std::cout << "Connect to server, IP address: ";
    //std::cin >> server_ip;

    //sf::IpAddress client_ip = sf::IpAddress::getPublicAddress();
    
    //"195.19.43.156"
    listener.listen(2000);
    std::cin >> server_ip;
    socket.connect(server_ip, 2001);

    out_packet << -1;
    socket.send(out_packet);
    out_packet.clear();

    listener.accept(server_socket);
    server_socket.receive(in_packet);
    in_packet >> player.point.X >> player.point.Y >> player.HP;
    std::cout << player.HP;
    in_packet.clear();

    sprite.setPosition(player.point.X, player.point.Y); 

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
                        out_packet << sf::Keyboard::Up;
                        break;
                    case sf::Keyboard::Down : 
                        downFlag=true;
                        out_packet << sf::Keyboard::Down;
                        break;
                    case sf::Keyboard::Left : 
                        leftFlag=true; 
                        out_packet << sf::Keyboard::Left;
                        break;
                    case sf::Keyboard::Right : 
                        rightFlag=true; 
                        out_packet << sf::Keyboard::Right;
                        break;
                    default : break;
                }

                socket.send(out_packet);
                out_packet.clear();

                server_socket.receive(in_packet);
                in_packet >> player.point.X >> player.point.Y >> player.HP;

                std::cout << sprite.getPosition().x << "    " << sprite.getPosition().y << std::endl;
                
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
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

            if (sprite.getRotation() != 90) {
                sprite.setRotation(90);
            } 
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

            if (sprite.getRotation() != 0) {
                sprite.setRotation(0);
            } 
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {

            if (sprite.getRotation() != 180) {
                sprite.setRotation(180);
            }
        }
        window.clear();
        sprite.setPosition(player.point.X, player.point.Y);
        window.draw(sprite);
        window.display();
        in_packet.clear();
    }
    return 0;
}


#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "message.pb.h"


using namespace google::protobuf;

typedef struct {
    float X;
    float Y;
} Point;

class Bullet {
    Point point;
    float speed;
    int direction;
    bool life;
    sf::Image image;

    Bullet(float x, float y, int dir): direction(dir) {
        point.X = x;
        point.Y = y;
        // image.loadFromFile("../image/tank_top.png"); 
        // image.createMaskFromColor(sd::Color(0, 0, 0));
        // sf::Texture.loadFromImage(image); 
        // sf::Sprite.setTexture(texture);
        // sf::FloatRect spriteSize = sprite.getLocalBounds();
        life = true;
    }
    void update(float time)
    {
        // switch (direction)

        // {
        //     case 0: dx = -speed; dy = 0;   break;
        //     case 1: dx = speed; dy = 0;   break;
        //     case 2: dx = 0; dy = -speed;   break;
        //     case 3: dx = 0; dy = speed;   break;
        // }

        // point.X += dx*time;
        // point.Y += dy*time;
        // if (getRect().intersects(obj[i].rect)) //если этот объект столкнулся с пулей,
        // {
        //     life = false;// то пуля умирает
        // }

        // sprite.setPosition(x+spriteSize.width/2.0, y+spriteSize.height/2.0);
    }
};

class Tank {
public:
    int HP;
    int dir;   //направление движения 1 - верх, 2 - вниз, 3 - влево, 4 - вправо
    Point point;
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
    std::string name;
    Tank(int health, float x, float y, sf::Color color): HP(health) {
        point.X = x;
        point.Y = y;
        image.loadFromFile("../image/tank_top.png");
        texture.loadFromImage(image); 
        sprite.setTexture(texture);
        sf::FloatRect spriteSize = sprite.getLocalBounds();
        sprite.setOrigin(spriteSize.width/2.0, spriteSize.height - spriteSize.width/2.0);
        sprite.setScale(0.2,0.2);
        sprite.setPosition(point.X, point.Y);
    }
    void update() {

    }
};


int main(int argc, char* argv[]){

	GOOGLE_PROTOBUF_VERIFY_VERSION;

    sf::TcpSocket socket;
    sf::Packet in_packet;
    sf::Packet out_packet;

    std::string server_ip;
    std::cout << "Connect to server, IP address: ";
    std::cin >> server_ip;

	sf::Socket::Status status = socket.connect(server_ip, 2000);
	if (status != sf::Socket::Done)
	{
    	// error...
	}

    sf::RenderWindow window(sf::VideoMode(640, 480), "Tanks SFML");

    Tank player = Tank(0, 0, 0, sf::Color::Red);

    // Flags for key pressed
    bool upFlag = false;
    bool downFlag = false;
    bool leftFlag = false;
    bool rightFlag = false; 
    
    std::string buffer = "";
    Player message_packet;

    while (window.isOpen()) {
        sf::Event event;

        buffer = "";
        socket.receive(in_packet);
        in_packet >> buffer;
        std::cout << "receive in_packet" << std::endl;
        in_packet.clear();

        if (message_packet.ParseFromString(buffer)) {
        	player.sprite.setPosition(message_packet.x(), message_packet.y());
        	std::cout << "receive ParseFromString" << std::endl;
        }
        std::cout << "***" << std::endl;
        while (window.pollEvent(event)) {
        	std::cout << "enter to pollEvent" << std::endl;
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
            	std::cout << "enter to KeyPressed" << std::endl;
                switch (event.key.code) {
                    case  sf::Keyboard::Escape : 
                        window.close(); 
                        break;
                    case sf::Keyboard::Up : 
                        upFlag = true;                     
                        message_packet.set_dir(Player_Dir_UP);
                        std::cout << "up" << std::endl;
                        if (player.sprite.getRotation() != 0) {
                			player.sprite.setRotation(0);
            			}                        
                        break;
                    case sf::Keyboard::Down : 
                        downFlag = true;
                        message_packet.set_dir(Player_Dir_DOWN);
                        std::cout << "down" << std::endl;
                        if (player.sprite.getRotation() != 180) {
                			player.sprite.setRotation(180);
            			}                        
                        break;
                    case sf::Keyboard::Left : 
                        leftFlag = true; 
                        message_packet.set_dir(Player_Dir_LEFT);
                        std::cout << "left" << std::endl;
                        if (player.sprite.getRotation() != 270) {
                			player.sprite.setRotation(270);
            			}                        
                        break;
                    case sf::Keyboard::Right : 
                        rightFlag = true; 
                        message_packet.set_dir(Player_Dir_RIGHT);
                        std::cout << "right" << std::endl;
                        if (player.sprite.getRotation() != 90) {
                			player.sprite.setRotation(90);
            			}	 
                        break;
                    case sf::Keyboard::Space :
                    	
                    	break;    
                    default : break;
                }
                
            }
            if (event.type == sf::Event::KeyReleased) {
                switch (event.key.code) {
                    case sf::Keyboard::Up : 
                        upFlag = false; 
                        break;
                    case sf::Keyboard::Down: 
                        downFlag = false; 
                        break;
                    case sf::Keyboard::Left: 
                        leftFlag = false; 
                        break;
                    case sf::Keyboard::Right: 
                        rightFlag = false; 
                        break;
                    default : break;
                }
            }
        }
        if (upFlag || downFlag || leftFlag || rightFlag) {
        	message_packet.set_state(1);
        }
        else {
        	message_packet.set_state(0);
        }

		buffer = "";
    	if (message_packet.SerializeToString(&buffer)){
    		out_packet << buffer;
    		socket.send(out_packet);
    		std::cout << "send out_packet" << std::endl;
    	}

        out_packet.clear();
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        //     if (player.sprite.getRotation() != 270) {
        //         player.sprite.setRotation(270);
        //     } 
        // }
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        //     if (player.sprite.getRotation() != 90) {
        //         player.sprite.setRotation(90);
        //     } 
        // }
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        //     if (player.sprite.getRotation() != 0) {
        //         player.sprite.setRotation(0);
        //     } 
        // }
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        //     if (player.sprite.getRotation() != 180) {
        //         player.sprite.setRotation(180);
        //     }
        // }
        window.clear();
        window.draw(player.sprite);
        window.display();
    } 
    return 0;
}


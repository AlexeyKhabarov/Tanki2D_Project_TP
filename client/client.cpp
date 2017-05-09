#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "message.pb.h"
#include "map.h"

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
    sf::Image image_bullet;
    sf::Texture texture_bullet;
    sf::Sprite sprite_bullet;

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

class Map {
public:
    sf::Image image_grass;
    sf::Image image_stone;
    sf::Texture texture_grass;
    sf::Texture texture_stone;
    sf::Sprite sprite_grass;
    sf::Sprite sprite_stone;
    Map() {
        image_grass.loadFromFile("../image/grass_32.png");
        texture_grass.loadFromImage(image_grass);
        sprite_grass.setTexture(texture_grass);

        image_stone.loadFromFile("../image/stone_32.png");
        texture_stone.loadFromImage(image_stone);
        sprite_stone.setTexture(texture_stone);
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
    float size_x;
    float size_y;
    Tank(int health, float x, float y, sf::Color color): HP(health) {
        point.X = x;
        point.Y = y;
        image.loadFromFile("../image/tank_top.png");
        texture.loadFromImage(image); 
        sprite.setTexture(texture);
        sf::FloatRect spriteSize = sprite.getLocalBounds();
        size_x = spriteSize.width;
        size_y = spriteSize.height;
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
    Map map;
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
		message_packet.set_size_x(player.size_x);
		message_packet.set_size_y(player.size_y);
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

        for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			if ((TileMap[i][j] == '0')) {

				map.sprite_grass.setPosition(j * 32, i * 32);
				window.draw(map.sprite_grass);
			}
			if ((TileMap[i][j] == 's')) {

				map.sprite_grass.setPosition(j * 32, i * 32);
				map.sprite_stone.setPosition(j * 32, i * 32);
				window.draw(map.sprite_grass);
				window.draw(map.sprite_stone);
			}			

		}

        window.draw(player.sprite);
        window.display();
    } 
    return 0;
}


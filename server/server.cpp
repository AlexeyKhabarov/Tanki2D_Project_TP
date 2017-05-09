#include <iostream>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include "../client/message.pb.h"
#include "../client/map.h"

using namespace google::protobuf;


typedef struct {
    float X;
    float Y;
} Point;

class Tank{
public:
    int HP;
    Point point;

    Tank(const int health, const float x, const float y): HP(health) {
        point.X = x;
        point.Y = y;
    }
};
void interactionWithMap(const Player& message_packet, Tank& player); //обработка столкновений
int main(int argc, char* argv[])
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    sf::IpAddress ip = sf::IpAddress::getLocalAddress();

    int key;
    const float move = 1;
    const float X_player_start = 200;
    const float Y_player_start = 200;
    const int hp = 100;

    sf::Packet in_packet;
    sf::Packet out_packet;

    sf::TcpListener listener;

    // bind the listener to a port
    if (listener.listen(2000) != sf::Socket::Done)
    {
        // error...
    }

    // accept a new connection
    sf::TcpSocket socket;
    if (listener.accept(socket) != sf::Socket::Done)
    {
        // error...
    } else {
        std::cout << "First player is connected" << std::endl;
    }
    
    Tank player = Tank(hp, X_player_start, Y_player_start);
    
    player.point.X = X_player_start;
    player.point.Y = Y_player_start;
    player.HP = hp;

    std::string buffer = "";
    Player message_packet;
    
    message_packet.set_x(player.point.X);
    message_packet.set_y(player.point.Y);
    message_packet.set_hp(player.HP);

    if (message_packet.SerializeToString(&buffer)){
        out_packet << buffer;
        socket.send(out_packet);
    }
    out_packet.clear();
    while (true){
        
        socket.receive(in_packet);
        in_packet >> buffer;
        std::cout << "receive in_packet" << std::endl;

        if (message_packet.ParseFromString(buffer)) {

            switch (message_packet.dir())
            {
                case 0:
                    std::cout << "Up" << std::endl;
                    if (message_packet.state() == 1) {
                        player.point.Y -= move;
                    }
                    message_packet.set_y(player.point.Y);
                    break;
                case 1:
                    std::cout << "Down" << std::endl;
                    if (message_packet.state() == 1) {
                        player.point.Y += move;
                    }
                    message_packet.set_y(player.point.Y);
                    break;
                case 2:
                    std::cout << "Left" << std::endl;
                    if (message_packet.state() == 1) {
                        player.point.X -= move;
                    }
                    message_packet.set_x(player.point.X);
                    break;
                case 3:
                    std::cout << "Right" << std::endl;
                    if (message_packet.state() == 1) {
                        player.point.X += move;
                    }
                    message_packet.set_x(player.point.X);
                    break;
            }

        }
        buffer = "";

        message_packet.set_hp(player.HP);

        if (message_packet.SerializeToString(&buffer)){
            out_packet << buffer;
            socket.send(out_packet);
            std::cout << "send out_packet" << std::endl;
        }
        
        out_packet.clear();
        in_packet.clear();
    }

    return 0;
}

void interactionWithMap(const Player& message_packet, Tank& player) {
    for (int i = player.point.Y / 32; i < (player.point.Y + message_packet.size_y()) / 32; i++) {
        for (int j = player.point.X / 32; j < (player.point.X + message_packet.size_x()) / 32; j++) {
            if (TileMap[i][j] == 's') {
                if (message_packet.dir() == 1) {
                    player.point.Y = i * 32 - message_packet.size_y();
                }
                if (message_packet.dir() == 0) {
                    player.point.Y = i * 32 + 32;
                }
                if (message_packet.dir() == 3) {
                    player.point.X = j * 32 - message_packet.size_x();
                }
                if (message_packet.dir() == 2){
                    player.point.X = j * 32 + 32;
                }
            }
        }
    }
}
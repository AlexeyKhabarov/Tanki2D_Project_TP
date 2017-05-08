#include <iostream>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include "../client/message.pb.h"


using namespace google::protobuf;

typedef struct{
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

int main(int argc, char* argv[])
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    sf::IpAddress ip = sf::IpAddress::getLocalAddress();

    int key;
    const float move = 0.5;
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


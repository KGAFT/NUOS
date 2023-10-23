
#include <MinimalSocket/tcp/TcpServer.h>
#include <iostream>
#include <Util/StringUtils.h>
int main(){
    std::cout<<StringUtils::contains("test", "ghthtreyhtrhgfd")<<std::endl;
    MinimalSocket::tcp::TcpServer server(static_cast<MinimalSocket::Port>(8090), MinimalSocket::AddressFamily::IP_V6);
    auto connection = server.acceptNewClient();
    MinimalSocket::Buffer messageBuffer{0,0};
    connection.receive(messageBuffer, MinimalSocket::Timeout(2500));
    int i = 0;
    while(i<messageBuffer.buffer_size){
        std::cout<<messageBuffer.buffer[i];
        i++;
    }
	return 0;
}


#include <MinimalSocket/tcp/TcpServer.h>
#include <iostream>
#include <Util/StringUtils.h>
#include <cstring>
#include "Server/Request.h"

int main(){
  //  MinimalSocket::tcp::TcpServer server(static_cast<MinimalSocket::Port>(8090), MinimalSocket::AddressFamily::IP_V6);
    //auto connection = server.acceptNewClient();
    MinimalSocket::Buffer messageBuffer{0,0};
  //  connection.receive(messageBuffer, MinimalSocket::Timeout(2500));
    int test = 124;
    std::string request = "12/test/request\n0id ";
    for(int i = 0; i<sizeof(int)/sizeof(char); i++){
        request+=((char*)(&test))[i];
    }
    request+='\n';
    Request requestR((char*)request.c_str());
    std::cout<<requestR.getId()<<std::endl;
    std::cout << requestR.getRoute().getRouteBase() << std::endl;
    std::cout<<((int*)requestR.getParams()[0].getData())[0]<<std::endl;
    test = 0;
    while(test<messageBuffer.buffer_size){
        std::cout<<messageBuffer.buffer[test];
        test++;
    }
	return 0;
}

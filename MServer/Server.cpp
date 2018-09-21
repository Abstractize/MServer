//
// Created by gabriel on 08/09/18.
//

#include "Server.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include "json.hpp"
//#include "ServerThread.h"
//#include "../AbstractDataType/DoubleList.h"
using json = nlohmann::json;


Server* Server::instance = NULL;

Server* Server::init() {
    if (instance == NULL){
        instance = new Server();
    }
    return instance;
}
Server::Server(){
    std::cout << "Loading server..." << std::endl;
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address,
             sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    while(true){
        std::cout << "Listening..." << std::endl;
        serverlisten();
    }

}
int Server ::serverlisten() {
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }else{
        std::cout << "Founding Connection..." << std::endl;
        acceptclient();
    }
}
int Server::acceptclient() {//Cambiar
    json j;
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                             (socklen_t*)&addrlen)<0))
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    std::cout << "Reading message..." << std::endl;
    try{
        valread = read( new_socket, buffer, 1024);
    }catch(int e) {

    }


    printf("%s\n",buffer );
    std::cout << "Sending message..." << std::endl;
    send(new_socket , hello , strlen(hello) , 0 );
    printf("Hello message sent\n");
    return 0;
}

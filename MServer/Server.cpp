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
#include "ServerThread.h"
#include "../AbstractDataType/DoubleList.h"
#define PORT 8080
Server* Server::init(int mall) {
    if (server == NULL){
        server = new Server();
    }else{
        //mem_malloc += mall;
    }
    return server;
}
int Server ::serverlisten() {
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }else{
        acceptclient();
    }
    serverlisten();
}
int Server::acceptclient() {
    char *hello = "Hello from server";
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                             (socklen_t*)&addrlen)<0))
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    valread = read( new_socket , buffer, 1024);
    printf("%s\n",buffer );
    send(new_socket , hello , strlen(hello) , 0 );
    printf("Hello message sent\n");
    return 0;
}

//
// Created by abstractize on 21/09/18.
//

#ifndef MSERVER_SERVERB_H
#define MSERVER_SERVERB_H

// Server side C/C++ program to demonstrate Socket programming
#include <iostream>

// Server side C/C++ program to demonstrate Socket programming
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include "json.hpp"
#include "ServerThread.h"
#include "../AbstractDataType/DoubleList.h"

#define PORT 8080


class ServerB {
private:
    static ServerB* instance;
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    DoubleList<ServerThread>* pool = new DoubleList<ServerThread>();
    ServerThread **temp;

    //char *hello = "Hello from server";
    ServerB();
    void acceptClient();

    void serverListen();

public:
    static ServerB* init(){

        if (instance == 0){
            instance = new ServerB();
        }
        return instance;
    }


};


#endif //MSERVER_SERVERB_H

//
// Created by gabriel on 08/09/18.
//

#ifndef MSERVER_SERVER_H
#define MSERVER_SERVER_H

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include "ServerThread.h"
#include "../AbstractDataType/DoubleList.h"

#define PORT 8080

class Server {
private:
    static Server* instance;
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    DoubleList<ServerThread> *Pool = new DoubleList<ServerThread>;

    Server();
    int serverlisten();
    int acceptclient();

public:

    static Server* init();
};


#endif //MSERVER_SERVER_H

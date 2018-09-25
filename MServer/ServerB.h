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

    //char *hello = "Hello from server";

    int acceptclient() {//Cambiar
        ServerThread* newThread = new ServerThread(new_socket);
        pool->append(newThread);

    }

    void serverListen() {
        if (bind(server_fd, (struct sockaddr *) &address,
                 sizeof(address)) < 0) {
            perror("bind failed");
            exit(EXIT_FAILURE);
        }
        if (listen(server_fd, 3) < 0) {
            perror("listen");
            exit(EXIT_FAILURE);
        }
        if ((new_socket = accept(server_fd, (struct sockaddr *) &address,
                                 (socklen_t *) &addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        acceptclient();
    }
    ServerB() {
        //if (instance == nullptr) {
            // Creating socket file descriptor
            std::cout << "Loading server..." << std::endl;
            if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
                perror("socket failed");
                exit(EXIT_FAILURE);
            }

            // Forcefully attaching socket to the port 8080
            if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                           &opt, sizeof(opt))) {
                perror("setsockopt");
                exit(EXIT_FAILURE);
            }
            address.sin_family = AF_INET;
            address.sin_addr.s_addr = INADDR_ANY;
            address.sin_port = htons(PORT);

            serverListen();
        //}
    }
public:
    static ServerB* init(){

        if (instance == 0){
            instance = new ServerB();
        }
        return instance;
    }


};


#endif //MSERVER_SERVERB_H

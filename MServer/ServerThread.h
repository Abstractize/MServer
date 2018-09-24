//
// Created by gabriel on 08/09/18.
//

#ifndef MSERVER_SERVERTHREAD_H
#define MSERVER_SERVERTHREAD_H


#include <unistd.h>
#include <cstdio>
#include "json.hpp"
#include <sys/socket.h>

using namespace std;
using json = nlohmann::json;

class ServerThread {
private:
    int new_socket, valread;
    char buffer[1024] = {0};
    json jreturn;
    json jsend;
    string ip;
    int space;


    int& MatrixGen(int fields);
public:
    ServerThread(int newsocket){
        new_socket = newsocket;
        valread = read( newsocket,buffer, 1024);
        jreturn = json::parse(buffer);
        printf("%s\n", buffer);
        //Meter varas del json, que se necesitan

        runThread();
    }
    void runThread() {
        while (true){
            try {
                valread = read(new_socket, buffer, 1024);
                printf("%s\n", buffer);
                send(new_socket, jsend.dump().c_str(), strlen(jsend.dump().c_str()), 0);
                printf("Hello message sent\n");

            }catch(exception& e){
                break;
            }
        }
    }
};


#endif //MSERVER_SERVERTHREAD_H

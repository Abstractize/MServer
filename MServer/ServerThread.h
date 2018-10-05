//
// Created by gabriel on 08/09/18.
//

#ifndef MSERVER_SERVERTHREAD_H
#define MSERVER_SERVERTHREAD_H


#include <unistd.h>
#include <cstdio>
#include "json.hpp"
#include "../AbstractDataType/List.h"
#include <sys/socket.h>
#include <iostream>

using namespace std;
using json = nlohmann::json;

class ServerThread {
private:
    int new_socket, valread;
    char buffer[1024] = {0};
    char buffer2[1024] = {0};
    json jreturn;
    json jsend;
    string ip;
    int buffer_position = 0;
    int space;
    int * bufferSpace; //Int por el momento, debe aceptar cualquier tipo
    //List *MapArray; //No se va a usar

    //int& MatrixGen(int fields);

public:
    ServerThread(int newsocket){
        new_socket = newsocket;
        valread = read( newsocket,buffer, 1024);
        jreturn = json::parse(buffer);
        printf("%s\n", jreturn.dump().c_str());
        ip = jreturn["IP"];
        //MapArray = new List(
                space = jreturn["Malloc"];
                        //);
        bufferSpace = (int*) malloc(space+1);
        //libera el Json
        jreturn.clear();
        //Devolver datos en Json
        jsend["info"] = "Hola, me llamo Roberto";
        send(newsocket,jsend.dump().c_str(),strlen(jsend.dump().c_str()),0);
        jsend.clear();
        std::cout<<space<<std::endl;
        runThread();
    }
    void runThread() {
        while (true){
            try {

                memset(buffer2,0,sizeof(buffer2));
                valread = read(new_socket, buffer2, 1024);
                printf("%s\n", buffer2);
                jreturn =  json::parse(buffer2);
                //Sacar métodos que se solicitan.
                if(jreturn["type"] == true){//Pide valor
                    int newpos = jreturn["value"];
                    jsend["Position"] = bufferSpace[newpos];
                    jreturn.clear();

                    send(new_socket, jsend.dump().c_str(), strlen(jsend.dump().c_str()), 0);
                    printf("Json sent\n");
                    std::cout<<jsend.dump()<<std::endl;
                    jsend.clear();
                }else{//Recibe valor
                    bool algo = jreturn["type"];//Corregir
                    int value = jreturn["value"];
                    jreturn.clear();
                    //Meter en el bufferSpace
                    bufferSpace[buffer_position] = value;
                    //Mandar posición
                    jsend["Position"] = buffer_position;
                    buffer_position++;

                    send(new_socket, jsend.dump().c_str(), strlen(jsend.dump().c_str()), 0);
                    //std::cout<<jsend.dump()<<std::endl;
                    printf("Json sent\n");
                    jsend.clear();
                }


            }catch(exception& e){
                free(bufferSpace);
                //Liberar de la lista/array
                break;
            }
        }
    }
};


#endif //MSERVER_SERVERTHREAD_H

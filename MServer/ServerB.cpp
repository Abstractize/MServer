//
// Created by abstractize on 21/09/18.
//

#include "ServerB.h"
ServerB* ServerB::instance = 0;
ServerB::ServerB() {
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
}

void ServerB::acceptClient(){//Cambiar
    ServerThread* newThread = new ServerThread(new_socket);
    temp[0] = newThread;
    //pool->append(newThread);

}
void ServerB::serverListen() {
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
    acceptClient();
}
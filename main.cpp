#include <iostream>
#include "MServer/Server.h"

int main() {
    Server* server = Server::init(40);
    return 0;
}
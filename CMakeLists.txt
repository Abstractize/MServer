cmake_minimum_required(VERSION 3.12)
project(MServer)

set(CMAKE_CXX_STANDARD 17)

add_executable(MServer main.cpp
        MServer/Server.h
        MServer/Server.cpp
        MServer/ServerThread.cpp
        MServer/ServerThread.h
        AbstractDataType/DoubleList.cpp
        AbstractDataType/DoubleList.h MServer/ServerB.cpp MServer/ServerB.h)
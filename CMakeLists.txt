cmake_minimum_required(VERSION 3.19)
project(Automat_z_napojami)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Automat_z_napojami
        automat.cpp
        automat.h
        blik.cpp
        blik.h
        card.cpp
        card.h
        coin.cpp
        coin.h
        drink.cpp
        drink.h
        payment.cpp
        payment.h
        test.cpp)

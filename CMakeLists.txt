cmake_minimum_required(VERSION 4.0)
project(KursAbdul)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(KursAbdul
        ArrayADT/main.cpp
        ArrayADT/arrayADT.h
        ArrayADT/arrayADT.hpp
        ArrayADT/StudentChallenges.h
)
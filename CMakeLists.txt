cmake_minimum_required(VERSION 3.16)
project(AnimalShelterSystem CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(animal_shelter
        src/main.cpp
        src/Animal.cpp
        src/ShelterUser.cpp
        src/Adopter.cpp
        src/ShelterStaff.cpp
        src/ShelterSystem.cpp)

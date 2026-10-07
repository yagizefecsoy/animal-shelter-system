//
// Created by Yağız Efe Çiçekçisoy on 23.11.2025.
//

#ifndef CMPE261_SHELTERSYSTEM_YAGIZEFECICEKCISOY_ADOPTER_H
#define CMPE261_SHELTERSYSTEM_YAGIZEFECICEKCISOY_ADOPTER_H

#include "Animal.h"
#include "ShelterUser.h"
#include <iostream>
#include <vector>
using namespace std;

class Adopter: public ShelterUser {

private: // Additional private attribute:
    vector<Animal*> adoptedPets; // vector of pointers to Animal objects.


public: // Methods:
    Adopter(string name, int userID); // Uses the base class constructor.
    void displayUserInfo() const override; // Overrides the inherited pure virtual method

    bool adoptPet(Animal *someAnimal); // Allows an adopter to adopt an animal if available.
    bool returnPet(Animal *someAnimal); // Allows an adopter to return an adopted animal.
              // ---> Both return true if successful. <---



};


#endif //CMPE261_SHELTERSYSTEM_YAGIZEFECICEKCISOY_ADOPTER_H
//
// Created by Yağız Efe Çiçekçisoy on 23.11.2025.
//

#ifndef CMPE261_SHELTERSYSTEM_YAGIZEFECICEKCISOY_SHELTERSTAFF_H
#define CMPE261_SHELTERSYSTEM_YAGIZEFECICEKCISOY_SHELTERSTAFF_H

#include "Animal.h"
#include "ShelterUser.h"
#include <iostream>
#include <vector>

class ShelterSystem;

using namespace std;

class ShelterStaff: public ShelterUser {
    public:
    ShelterStaff(string name,int userID); // Uses the base class constructor.
    void displayUserInfo() const override; // Overrides the pure virtual method.
    void addAnimal(ShelterSystem* system, Animal *newAnimal); // Allows the staff to add a new animal to the shelter.
    //--> We added the ShelterSystem class as a parameter to be able to make use of the implementations inside them.
    void removeAnimal(ShelterSystem* system, const string& animalID); // Removes an animal by its ID.
    //--> We added the ShelterSystem class as a parameter to be able to make use of the implementations inside them.
};


#endif //CMPE261_SHELTERSYSTEM_YAGIZEFECICEKCISOY_SHELTERSTAFF_H
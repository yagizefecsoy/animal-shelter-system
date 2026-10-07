//
// Created by Yağız Efe Çiçekçisoy on 23.11.2025.
//

#include "ShelterStaff.h"
#include "ShelterSystem.h"
#include <iostream>


ShelterStaff::ShelterStaff(string name, int userID):ShelterUser(name, userID) {}
   // Uses the parent class constructor.

void ShelterStaff::displayUserInfo() const { // Overrides the pure virtual method and displays staff info.
   cout << "Staff: " << name << " (ID: " << userID << ")" << endl;
}

void ShelterStaff::addAnimal(ShelterSystem* system,Animal *someAnimal) {
   // The implementation part of this method will be handled inside ShelterSystem...
   cout << "Staff: " << name << " is adding a new animal: " << someAnimal->getName() << endl;
   // In this line:
   system->addAnimal(someAnimal);
}

void ShelterStaff::removeAnimal(ShelterSystem* system,const string& someAnimalID) {
   // The implementation part of this method will be handled inside ShelterSystem...
   cout << "Staff: " << name << " is removing the animal with the ID: " << someAnimalID << endl;
   // In this line:
   system->removeAnimal(someAnimalID);
}


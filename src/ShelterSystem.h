//
// Created by Yağız Efe Çiçekçisoy on 23.11.2025.
//

#ifndef CMPE261_SHELTERSYSTEM_YAGIZEFECICEKCISOY_SHELTERSYSTEM_H
#define CMPE261_SHELTERSYSTEM_YAGIZEFECICEKCISOY_SHELTERSYSTEM_H
#include <iostream>
#include <vector>
#include <string>
#include "Animal.h"
#include "ShelterUser.h"
using namespace std;

class Adopter;
class ShelterSystem {

// THESE 2 VECTORS HOLD THE MOST SIGNIFICANT DATAS OF THE WHOLE PROJECT:
     private:
     vector<Animal*> animals; // Holds all the animals in the shelter.
     vector<ShelterUser*> users; // Holds all the users.
     Animal* searchAnimalRecursive(const string& name, int index) const; // This is the helper of the main searchAnimal method
                                                                         // Because we need an index to be recursive !

     public:

     ShelterSystem();

     void addUser(ShelterUser* newUser); // Adds a new user to the system.

     void addAnimal(Animal* newAnimal); // Allows the staff to add a new animal to the shelter.

     void removeAnimal(string animalID); // Removes an animal by its ID.

     Animal* searchAnimal(const string& name) const; // Searches for an animal by name using a recursive search algorithm.

     void displayAllAnimals() const; // Displays information on all animals in the shelter, including the
                              // total count using Animal::getTotalAnimals().

     void displayAllUsers() const; // Displays information on all users.

    ~ShelterSystem(); // Destructor.




};


#endif //CMPE261_SHELTERSYSTEM_YAGIZEFECICEKCISOY_SHELTERSYSTEM_H
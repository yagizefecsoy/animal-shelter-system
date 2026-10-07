//
// Created by Yağız Efe Çiçekçisoy on 23.11.2025.
//

#include "Adopter.h"
#include "Animal.h"
#include <iostream>
#include <vector>
#include <stdexcept>

// Uses the base class constructor.
Adopter::Adopter(string name, int userID)
    : ShelterUser(name, userID)
{
    // adoptedPets starts empty automatically
}


void Adopter::displayUserInfo() const { // Overrides the inherited pure virtual method
    cout << "Adopter: " << name << " (ID: " << userID << ")" << endl;
}


bool Adopter::adoptPet(Animal *someAnimal) {
    // Allows an adopter to adopt an animal if available.
    if (someAnimal == nullptr) { throw runtime_error("someAnimal == nullptr"); } // If such animal does not exist, we throw an exception.
    if (someAnimal->isItAdopted() == true ) { // First we check if such animal is already adopted.
        cout << someAnimal->getName() << " is already adopted!" << endl;
        return false; } // Operation not successful.
    else { // If not already adopted, then we carry on as follows:
        cout << " Adopter " << name << " is adopting " << someAnimal->getName() << endl; // Output the operation.
        someAnimal->setAdoptionStatus(true); // The animal is now adopted.
        adoptedPets.push_back(someAnimal); // Add the animal to the vector of adopted animals.
        return true; // Operation successful.
    }
}

bool Adopter::returnPet(Animal *someAnimal) { // Allows an adopter to return an adopted animal.
    if (someAnimal == nullptr) {throw runtime_error("You have not adopted an animal as such!");}
    // First we check if such animal exists in the adopters list of adopted animals
    for (int i = 0; i < adoptedPets.size(); ++i) {
        // We have to iterate through the list of adopted animals to figure out the index of this specific animal.
        // And then we can remove it using its index. To remove an item from a vector, we need its index.
        if (adoptedPets[i] == someAnimal) {
            string petName =someAnimal->getName();
            adoptedPets.erase(adoptedPets.begin() + i); // We remove it from the adopter's list of adopted animals.
            someAnimal->setAdoptionStatus(false); // Then, we set the animal back to unadopted.

            cout << "Adopter " << name << " returned " << petName << endl; // The output

            return true;
        }
    }
return false;

}



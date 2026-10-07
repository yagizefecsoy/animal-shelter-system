//
// Created by Yağız Efe Çiçekçisoy on 23.11.2025.
//

#include "ShelterSystem.h"
#include "Adopter.h"
#include "ShelterStaff.h"
#include <iostream>
#include <stdexcept>
#include <typeinfo>

ShelterSystem::ShelterSystem() { // Opening sentence in the .pdf
    cout << "Animal Shelter System Initialized." << endl;
}

ShelterSystem::~ShelterSystem() { // IMPORTANT POINT !!
    // We use the destructor to free up memory manually. This a very important point in C++
    // because we are dealing with a large amount of objects and memory has to be freed up manually.
     for (Animal* a : animals) {
         delete a;
     }
    for (ShelterUser* b : users) {
        delete b;
    }

    cout << "All memory cleared" << endl;

    }

void ShelterSystem::addUser(ShelterUser* newUser) { // Adds a new user to the system.
    users.push_back(newUser);

    if (typeid(*newUser) == typeid(Adopter)) {
        cout << "Adding new adopter: ";
    }
    else if (typeid(*newUser) == typeid(ShelterStaff)) {
        cout << "Adding new staff: ";
    }
    else {
        cout << "Adding new UNKNOWN type";
    }

    cout << newUser->getName() << " (ID: " << newUser->getUserID() << ")" << endl;

}

void ShelterSystem::addAnimal(Animal* newAnimal) { // Allows the staff to add a new animal to the shelter.
    animals.push_back(newAnimal);

    cout << "Adding animal: " << newAnimal->getName() << " (" << newAnimal->getSpecies() << "), ID: " << newAnimal->getAnimalID() << endl;
    cout << "Total animals: " << Animal::getTotalAnimals() << endl;
}


void ShelterSystem::removeAnimal(string animalID) { // Removes an animal by its ID.

    for (int i = 0; i < animals.size(); ++i) {
        if (animals[i]->getAnimalID() == animalID) {
            if (animals[i]->isItAdopted()){
                throw runtime_error("Cannot delete animal '" + animals[i]->getName() + "' because it is currently adopted!");}
            string petName = animals[i]->getName();
            delete animals[i]; // deleting it from heap -> manual memory control
            animals.erase(animals.begin() + i); // then we remove from the vector

            cout << "Removing animal: " << petName << " (" << animalID << ")" << endl;
            return;
        }
    }

    throw runtime_error( "Animal with ID: " + animalID + " not found!");

}

Animal* ShelterSystem::searchAnimal(const string& name) const { // Directly passes the search operation to its "RECURSIVE" Helper !!!.
    return searchAnimalRecursive(name,0);
}


Animal* ShelterSystem::searchAnimalRecursive(const string& name,int index) const { // Searches for an animal by name using a recursive search algorithm.
    if (index >= animals.size()) {
        return nullptr;
    }

    if (animals[index]->getName() == name) { // If found; returns the animal.
        return animals[index];
    }

    return searchAnimalRecursive(name, index + 1); // If not found; goes recursive...
}

void ShelterSystem::displayAllAnimals() const {
    // Displays information on all animals in the shelter, including the
    // total count using Animal::getTotalAnimals().
    cout << "Displaying all animals: " << endl;

    for (Animal* a : animals) {
        a->displayInfo();
    }
    cout << "Total Animals: " << Animal::getTotalAnimals() << endl;
}


void ShelterSystem::displayAllUsers() const { // Displays information of all users.
    cout << "Displaying all users: " << endl;
    for (ShelterUser* user : users) {
        user->displayUserInfo();
    }
}

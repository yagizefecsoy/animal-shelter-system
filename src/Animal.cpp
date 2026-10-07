//
// Created by Yağız Efe Çiçekçisoy on 23.11.2025.
//

#include "Animal.h"
#include <iostream>
using namespace std;

int Animal::totalAnimals = 0; // Initializing the static variable

// Constructor to initialize all attributes and increment totalAnimals

Animal::Animal(string name,string species,string animalID) {
    this->name = name;
    this->species = species;
    this->animalID = animalID;
    isAdopted = false;

    totalAnimals++;
}


void Animal::displayInfo() const { // Displays animal details
    cout << "Name: " << name << ", Species: " << species << ", ID: " << animalID << ", Adopted: " << (isItAdopted() ? "Yes" : "No") << endl;
}


void Animal::setAdoptionStatus(bool sta){ // Sets the adoption status of the animal.
    isAdopted = sta;
}


bool Animal::isItAdopted() const { // Returns whether the animal is adopted.
    return isAdopted;

}

int Animal::getTotalAnimals(){ // Static method that returns the total number of animals.
    return totalAnimals;
}
// Getters & Setters:

string Animal::getName() const {return name;}
string Animal::getSpecies() const {return species;}
string Animal::getAnimalID() const {return animalID;}
// isItAdopted() already does this...
// getTotalAnimals() already does this...

void Animal::setName(string name){this->name = name;}
void Animal::setSpecies(string species){this->species = species;}
void Animal::setAnimalID(string animalID){this->animalID = animalID;}
// setAdoptionStatus(bool sta) already does this...
// static variable is only initialized inside the Constructor...


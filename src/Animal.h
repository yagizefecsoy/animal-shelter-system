//
// Created by Yağız Efe Çiçekçisoy on 23.11.2025.
//

#ifndef CMPE261_SHELTERSYSTEM_YAGIZEFECICEKCISOY_ANIMAL_H
#define CMPE261_SHELTERSYSTEM_YAGIZEFECICEKCISOY_ANIMAL_H

#include <iostream>
#include <string>
using namespace std;

class Animal {
     // ===== THE ATTRIBUTES FOR THE ANIMALS =====:
     private:
     string name;
     string species; // Species of the animal
     string animalID; // Unique ID for each animal
     bool isAdopted; // Indicates if the animal is currently adopted

     // Static variable that keeps track of the total number of animals registered in the shelter:
     static int totalAnimals;

     // ===== METHODS =====:
     public:
     // Constructor to initialize all attributes and increment totalAnimals
     Animal(string name,string species,string animalID);
          // will also increment totalAnimals
          // A new added animal can not be adopted already, so we will start it with a default value: false

     void displayInfo() const ; // Displays animal details
     void setAdoptionStatus(bool sta); // Sets the adoption status of the animal.
     bool isItAdopted() const ; // Returns whether the animal is adopted.
     static int getTotalAnimals(); // Static method that returns the total number of animals.

     // Getters & Setters:

     string getName() const ;
     string getSpecies() const ;
     string getAnimalID() const ;
     // isItAdopted() already does this...
     // getTotalAnimals() already does this...

     void setName(string name);
     void setSpecies(string species);
     void setAnimalID(string animalID);
     // setAdoptionStatus(bool sta) already does this...
     // static variable is only initialized inside the Constructor...

};


#endif //CMPE261_SHELTERSYSTEM_YAGIZEFECICEKCISOY_ANIMAL_H
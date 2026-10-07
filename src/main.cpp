#include <iostream>
#include "ShelterSystem.h"
#include "ShelterUser.h"
#include "Adopter.h"
#include "ShelterStaff.h"
#include "Animal.h"


using namespace std;


int main() {

    // ================================================================
    // SAMPLE RUN — 1
    // System Init + User Add + Animal Add + Listing
    // ================================================================

    cout << "==================== SAMPLE RUN — 1 START ====================\n" << endl;

    {
        ShelterSystem system;

        // Users
        ShelterUser* adopter1 = new Adopter("John Doe", 101);
        ShelterUser* staff1   = new ShelterStaff("Sarah Smith", 102);

        system.addUser(adopter1);
        system.addUser(staff1);

        cout << endl;

        // Add animals
        ShelterStaff* ss = (ShelterStaff*) staff1;

        ss->addAnimal(&system, new Animal("Bella", "Dog", "D001"));
        ss->addAnimal(&system, new Animal("Milo", "Cat", "C002"));

        cout << endl;

        // Display animals
        system.displayAllAnimals();
        cout << endl;

        // Display users
        system.displayAllUsers();
    }

    cout << "\n==================== SAMPLE RUN — 1 END ====================\n" << endl;


    // ================================================================
    // SAMPLE RUN — 2
    // Search + Adopt + Return + Error Handling
    // ================================================================

    cout << "==================== SAMPLE RUN — 2 START ====================\n" << endl;

    {
        ShelterSystem system;

        // Users
        ShelterUser* adopter = new Adopter("Emily Carter", 201);
        ShelterUser* staff   = new ShelterStaff("Daniel Park", 202);

        system.addUser(adopter);
        system.addUser(staff);

        cout << endl;

        // Add animals
        ShelterStaff* ss = (ShelterStaff*) staff;
        ss->addAnimal(&system, new Animal("Loki", "Dog", "D010"));
        ss->addAnimal(&system, new Animal("Coco", "Bird", "B005"));

        cout << endl;

        // Search animal
        cout << "Searching for: Loki" << endl;
        Animal* found = system.searchAnimal("Loki");

        if (found)
            found->displayInfo();
        else
            cout << "[ERROR] Animal not found!" << endl;

        cout << endl;

        // Adoption
        Adopter* ad = (Adopter*) adopter;

        try {
            ad->adoptPet(found);
            cout << "Adoption successful." << endl;
        }
        catch (const exception& e) {
            cout << "[ERROR] " << e.what() << endl;
        }

        cout << endl;

        // Try adopt again (should fail)
        ad->adoptPet(found);

        cout << endl;

        // Return
        try {
            ad->returnPet(found);
            cout << "Return successful." << endl;
        }
        catch (const exception& e) {
            cout << "[ERROR] " << e.what() << endl;
        }

        cout << endl;

        // Wrong search
        cout << "Searching for: GhostDog" << endl;
        Animal* wrong = system.searchAnimal("GhostDog");

        if (!wrong)
            cout << "[ERROR] Animal not found!" << endl;
    }

    cout << "\n==================== SAMPLE RUN — 2 END ====================\n" << endl;


    // ================================================================
    // SAMPLE RUN — 3
    // Remove + Adopted-While-Remove Error + Final List
    // ================================================================

    cout << "==================== SAMPLE RUN — 3 START ====================\n" << endl;

    {
        ShelterSystem system;

        // Users
        ShelterUser* adopter = new Adopter("Michael Reed", 301);
        ShelterUser* staff   = new ShelterStaff("Olivia Turner", 302);

        system.addUser(adopter);
        system.addUser(staff);

        cout << endl;

        // Add animals
        ShelterStaff* ss = (ShelterStaff*) staff;
        ss->addAnimal(&system, new Animal("Max", "Dog", "D020"));
        ss->addAnimal(&system, new Animal("Luna", "Cat", "C021"));

        cout << endl;

        // Adopt
        Adopter* ad = (Adopter*) adopter;
        Animal* max = system.searchAnimal("Max");

        ad->adoptPet(max);
        cout << "Adoption successful." << endl << endl;

        // Remove while adopted (error)
        cout << "Trying to remove Max while adopted..." << endl;

        try {
            ss->removeAnimal(&system, "D020");
        }
        catch (const exception& e) {
            cout << "[ERROR] " << e.what() << endl;
        }

        cout << endl;

        // Return
        ad->returnPet(max);

        // Remove again (works)
        ss->removeAnimal(&system, "D020");

        cout << endl;

        // Final list
        system.displayAllAnimals();
    }

    cout << "\n==================== SAMPLE RUN — 3 END ====================\n" << endl;


    return 0;
}





//
// Created by Yağız Efe Çiçekçisoy on 23.11.2025.
//

#ifndef CMPE261_SHELTERSYSTEM_YAGIZEFECICEKCISOY_SHELTERUSER_H
#define CMPE261_SHELTERSYSTEM_YAGIZEFECICEKCISOY_SHELTERUSER_H

#include <iostream>
#include <string>
using namespace std;

class ShelterUser {

    // !!!!!! --- IMPORTANT CLASS INFOs --- !!!!!!:

// (1)--> Although the PDF only tells us: "displayUserInfo() is a virtual function, we justify that it must be a
// --PURE VIRTUAL METHOD-- because for the ShelterUser class to be abstract, it must contain at least one pure virtual method.
// Otherwise, it would be a normal parent class open to override but not a abstract one !!!

// (2)--> As every well-known textbook tells: Sutter, Stroustrup, Meyers…
// “Every polymorphic base class MUST have a virtual destructor.”


// ==== ATTRIBUTES ====:
protected: // because the derived classes can access:
    string name; // Name of the user.
    int userID; // Unique ID of the user.

    // ==== METHODS ====:
public:
    ShelterUser(string name,int userID); // Constructor to initialize the attributes.
    virtual void displayUserInfo() const = 0; // Pure Virtual function, make this class abstract.
    virtual ~ShelterUser() {} // The virtual destructor.


    // Getters & Setters:

    string getName() const ;
    int getUserID() const ;

    void setName(string name) ;
    void setUserID(int userID);
};


#endif //CMPE261_SHELTERSYSTEM_YAGIZEFECICEKCISOY_SHELTERUSER_H
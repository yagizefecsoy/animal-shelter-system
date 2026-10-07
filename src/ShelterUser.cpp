//
// Created by Yağız Efe Çiçekçisoy on 23.11.2025.
//

#include "ShelterUser.h"


ShelterUser::ShelterUser(string name,int userID) { // Constructor to initialize the attributes.
    this->name = name;
    this->userID = userID;
}

// a pure virtual method can never have an implementation.


// the virtual destructor both, usually & professionally, is taken care of in the header.


// Getters & Setters:

string ShelterUser::getName() const {
    return name;
}

int ShelterUser::getUserID() const {
    return userID;
}

void ShelterUser::setName(string name) {
    this->name = name;
}

void ShelterUser::setUserID(int userID) {
    this->userID = userID;
}

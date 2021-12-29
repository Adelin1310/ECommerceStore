#include "User.h"
#include <fstream>
#include <iostream>
#include "../security.cpp" 


Store::User::User(char* userName, char* password, char* email, char* phone,bool &success){
    this->id = Store::overallID++;
    char* HASH = Security::Hash(password, 1);
    if(Security::CheckUserAvailability(userName, email, phone))
        Security::usersDB_w<<id<<":{"<<userName<<"}X{"<<HASH<<"}X{"<<email<<"}X{"<<phone<<"}X\n", success = true;
    else{
        std::cout<<"Error!\nThere already exists a user with that username, email or phone. Try again!\n";
        Store::overallID--;
        success = false;
    }
}

Store::User::~User(){delete this;}

void Store::User::ChangePassword(char* oldPassword, char* newPassword){
    if(Security::CompareHash(Security::Hash(oldPassword, 1), id))
        this->Password = newPassword;
    else
        std::cout<<"Wrong password!\n";
}

void Store::User::ChangeUserName(char* password, char* newUserName){
    if(Security::CompareHash(Security::Hash(password, 1), id))
        this->UserName = newUserName;
    else
        std::cout<<"Wrong password!\n";
}

char* Store::User::GetEmail(){
    return this->Email;
}

char* Store::User::GetPhoneNumber(){
    return this->Phone;
}
#pragma once
#include "./Headers/User.h"
namespace Store
{
    void Initialize();
    void Menu();
    bool LogIn(char* userName, char* password);
    bool SignUp(char* userName, char* password, char* email, char* phone);
} // namespace Store

#include "./sfunc.h"
#include <iostream>
#include "security.h"
#include "./Headers/User.cpp"
#include <windows.h>

void Store::Initialize()
{
    std::cout << "Welcome!\n\n1.Login\n2.Signup";
    char c;
    std::cin.get(c);
    std::cin.clear();
    std::cin.ignore(1);
    if (c == '1')
    {
        char UserName[30];
        char Password[30];
        std::cout << "Username:";
        std::cin.getline(UserName, 30);
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Password:";
        std::cin.getline(Password, 30);
        std::cin.clear();
        std::cin.ignore(100, '\n');
        if (Store::LogIn(UserName, Password))
            Store::Menu();
        else
        {
            system("cls");
            std::cout << "Wrong username or password!\nTry Again\nPress any key to continue...";
            c = getchar();
        }
    }
    else if (c == '2')
    {
        system("cls");
        char Username[30], Password[30], Email[50], Phone[15];

        std::cout << "Username:";
        std::cin.clear();
        std::cin.getline(Username, 30);

        system("cls");
        std::cout << "Password:";
        std::cin.clear();
        std::cin.getline(Password, 30);
        system("cls");
        std::cout << "Email:";
        std::cin.clear();
        std::cin.getline(Email, 50);
        system("cls");
        std::cout << "Phone:";
        std::cin.clear();
        std::cin.getline(Phone, 15);
        system("cls");

        if (Store::SignUp(Username, Password, Email, Phone))
        {
            system("cls");
            std::cout << "Congratulations, your account has been created.\nYou will be redirected to the initial page.\nSelect Login and proceed.\nThank You!\n";
            Sleep(5000);
            system("cls");
            Store::Initialize();
            return;
        }
        else
        {
            Store::Initialize();
            return;
        }
    }
    else
    {
        system("cls");
    }
}

bool Store::SignUp(char *userName, char *password, char *email, char *phone)
{
    bool success = false;
    User newUser = Store::User(userName, password, email, phone, success);
    if(success == false)
        newUser.~User();
    return success;
}

bool Store::LogIn(char *userName, char *password)
{
    return true;
}

void Store::Menu()
{
    system("cls");
    char *menu;
    strcpy(menu, "1.Categories\n2.Cart\n3.Exit");
    std::cout << menu;
    char c = getchar();
    if (c == '3')
        system("exit");
}
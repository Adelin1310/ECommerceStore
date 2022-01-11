#pragma once
#include "./Headers/User.h"
#include <fstream>
namespace Security
{
    std::ofstream usersDB_w("users.dbf", std::ios_base::app);
    std::ifstream usersDB_r("users.dbf", std::ios_base::in);
    const char* secret = "secret-key";
    bool CheckUserAvailability(char* userName, char* email, char* phone);
    char* GetUserHash(const unsigned int userId);
    bool CompareHash(char* Hash,unsigned int userId);
    char* Hash(char* password, bool conversion_type);

} // namespace Security

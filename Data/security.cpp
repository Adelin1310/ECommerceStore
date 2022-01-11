#include "security.h"
#include <cstring>
#include <fstream>
#include "converts.cpp"
char *Security::Hash(char *pass, bool conversion_type)
{
    const char *sec = Security::secret;
    int hashAux = 0;
    for (unsigned int i = 0; i < strlen(sec); i++)
        hashAux += sec[i];
    hashAux = std::DecToBin(hashAux);

    char *HASH = new char[strlen(pass)];

    unsigned int *hashIntArr = new unsigned int[strlen(pass)];
    if (conversion_type)
        for (unsigned int i = 0; i < strlen(pass); i++)
            hashIntArr[i] = pass[i] + hashAux;
    else
    {
        for (unsigned int i = 0; i < strlen(pass); i++)
            hashIntArr[i] = pass[i] - hashAux;
    }
    for (unsigned int i = 0; i < strlen(pass); i++)
        HASH[i] = hashIntArr[i];
    return HASH;
}

int GetCharacterCount(){
    char c;
    int result = 0;
    while(Security::usersDB_r>>c) result++;

    Security::usersDB_r.clear();
    Security::usersDB_r.seekg(0, std::ios_base::beg);
    return result;
}

char* GetUser(unsigned int userId)
{
    char* Line;
    char* result = nullptr;
    bool is_found = false;
    Line = new char[100];
    while(!Security::usersDB_r.eof() && !is_found){
        Security::usersDB_r.getline(Line, 100, '\n');
        unsigned int id = 0;
        char* aux;
        strcpy(aux, Line);
        aux = strtok(aux, ":");
        for (unsigned int i = 0; i < strlen(aux); i++)
            if(isdigit(aux[i]))
                id = id * 10 + (aux[i] - 48);
        
        if(id == userId) is_found = true, strcpy(result, Line);
        strcpy(Line, "\0");
    }


    return result;

        
}

bool Security::CheckUserAvailability(char* userName, char* email, char* phone){
    char* users = new char[GetCharacterCount()];
    if(GetCharacterCount()!= 0)
    {
        unsigned int index = 0;
        while(!Security::usersDB_r.eof())
            Security::usersDB_r >> users[index++];
        
        if(strstr(users, userName) != NULL)
            return false;
        if(strstr(users, email)!= NULL)
            return false;
        if(strstr(users, phone)!= NULL)
            return false;

        return true;
    }
    else return true;
}

char* Security::GetUserHash(unsigned int userId){
    char* user = GetUser(userId);
    
    char* aux = new char[strlen(user) + 1];
    strcpy(aux, user);
    char* aux2 = strtok(aux, "X{");
    unsigned int i = 2;
    while(i > 0)
    {
        aux2 = strtok(aux, "}X{");
        i--;
    }

    return aux2;

}

bool Security::CompareHash(char* Hash, unsigned int userId){
    char* dbHash = Security::GetUserHash(userId);
    for (unsigned int i = 0; i < strlen(Hash); i++)
        if(Hash[i] != dbHash[i]) return false;
    return true;
}
#pragma once

namespace Store
{
    static unsigned int overallID = 0;
    class User
    {
    private:
        unsigned int id;
        char *UserName;
        char *Email;
        char *Password;
        char *Phone;

    public:
        char *GetEmail();
        char *GetPhoneNumber();
        void ChangePassword(char *oldPassword, char *newPassword);
        void ChangeUserName(char *password, char *newUsername);
        User(char *userName, char *password, char *email, char *phone, bool &succes);
        ~User();
    };
} // namespace Store

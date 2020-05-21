#pragma once
#include <string>
using namespace std;

class User {
private:
    string name;
    string password;
public:
    User();
    User(string name, string password);
    User(const User& user);
    ~User();

    User* clone();

    string getName();
    string getPassword();

    void setName(string newValue);
    void setPassword(string newValue);

    User& operator = (const User& u);
    bool operator == (const User& u);
    string toString(string delim);
};


#pragma once
#include <string>
#include <iostream>
#include <exception>

using namespace std;

class MyException : public exception {
private:
    string message;
public:
    MyException(string message);

    string getMessage();
};

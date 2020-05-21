#pragma once
#include "Artist.h"
#include <exception>
#include <string>

using namespace std;

class ValidationArtist {
protected:
    int errors;
    string message;
public:
    ValidationArtist();
    ~ValidationArtist();

    int Validate(Artist*);
    string toString();
};
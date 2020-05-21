#pragma once
#include <Windows.h>
#include <cwchar>
#include <vector>
#include <string>
#include "Service.h"
#include "Movie.h"
#include "Artist.h"
#include "User.h"
#include "ValidationArtist.h"
#include "MyException.h"
using namespace std;

class Ui {
private:
	Service s;

	void Meniu();

	void login();

	void findByDate();
	void buyTickets();
	void AddA();
	void printAllMovie();
	void printAllArtist();
public:
	Ui();
	Ui(Service& s);
	~Ui();
	void start();
};


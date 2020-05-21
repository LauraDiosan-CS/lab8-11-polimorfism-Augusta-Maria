#pragma once
#include "Movie.h"
#include "Artist.h"
#include "User.h"
#include "ValidationArtist.h"
#include "ValidationException.h"
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Repo {
protected:
	vector<Movie*> movies;
	vector<Artist*> artists;
	vector<User*> users;
	string fileName;
	ValidationArtist* ValidateA;
public:
	Repo();
	Repo(string fileName, ValidationArtist* ValidateA);
	~Repo();
	void setFileName(string fileName);

	vector<Movie*> getAllM();
	vector<Artist*> getAllA();
	vector<User*> getAllU();

	int getSizeM();
	int getSizeA();
	int getSizeU();

	Movie* getMovie(int poz);
	Artist* getArtist(int poz);
	User* getUser(int poz);

	void AddM(Movie* m);
	void AddA(Artist* a);
	void AddU(User* u);

	void UpdateM(Movie* om, Movie* nm);
	void UpdateA(Artist* oa, Artist* na);
	void UpdateU(User* ou, User* nu);

	void DeleteM(Movie* m);
	void DeleteA(Artist* a);
	void DeleteU(User* u);

	void emptyRepo();

	virtual void loadFromFile() = 0;
	virtual void saveToFile() = 0;
};



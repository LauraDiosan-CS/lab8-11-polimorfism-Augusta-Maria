#pragma once
#include "Repo.h"
using namespace std;

class RepoFileCSV : public Repo {
public:
	RepoFileCSV();
	RepoFileCSV(string fileName, ValidationArtist* ValidateA);
	~RepoFileCSV();
	void loadFromFile();
	void saveToFile();
};
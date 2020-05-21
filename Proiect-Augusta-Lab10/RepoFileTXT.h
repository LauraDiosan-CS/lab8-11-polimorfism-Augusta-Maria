#pragma once
#include "Repo.h"
using namespace std;

class RepoFileTXT : public Repo {
public:
	RepoFileTXT();
	RepoFileTXT(string fileName, ValidationArtist* ValidateA);
	~RepoFileTXT();
	void loadFromFile();
	void saveToFile();
};
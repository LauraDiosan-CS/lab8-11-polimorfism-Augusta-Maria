#include "Repo.h"

Repo::Repo() {
	this->ValidateA = new ValidationArtist();

}

Repo::Repo(string fileName, ValidationArtist* ValidateA) {
	this->fileName = fileName;
	this->ValidateA = ValidateA;
}

Repo::~Repo() {

}

void Repo::setFileName(string fileName) {
	this->fileName = fileName;
}

vector<Movie*> Repo::getAllM() {
	return this->movies;
}

vector<Artist*>Repo::getAllA() {
	return this->artists;
}

vector<User*> Repo::getAllU() {
	return this->users;
}

int Repo::getSizeM() {
	return this->movies.size();
}

int Repo::getSizeA() {
	return this->artists.size();
}

int Repo::getSizeU() {
	return this->users.size();
}

Movie* Repo::getMovie(int poz) {
	if (poz >= 0 && poz < this->getSizeM()) {
		return this->movies[poz]->clone();
	}
	return new Movie();
}

Artist* Repo::getArtist(int poz) {
	if (poz >= 0 && poz < this->getSizeA()) {
		return this->artists[poz]->clone();
	}
	return new Artist();
}

User* Repo::getUser(int poz) {
	if (poz >= 0 && poz < this->getSizeU()) {
		return this->users[poz]->clone();
	}
	return new User();
}

void Repo::AddM(Movie* m) {
	this->movies.push_back(m->clone());
	this->saveToFile();
}

void Repo::AddA(Artist* a) {
	this->ValidateA = new ValidationArtist();
	if (((ValidationArtist*)ValidateA)->Validate(a) == 0) {
		this->artists.push_back(a->clone());
		this->saveToFile();
	}
	else {
		throw ValidationException(this->ValidateA->toString());
	}
}

void Repo::AddU(User* u) {
	this->users.push_back(u->clone());
	this->saveToFile();
}

void Repo::UpdateM(Movie* om, Movie* nm) {
	for (int i = 0; i < this->movies.size(); i++) {
		if (*(this->getMovie(i)) == *om) {
			delete this->movies[i];
			this->movies[i] = nm->clone();
			this->saveToFile();
			return;
		}
	}
}

void Repo::UpdateA(Artist* oa, Artist* na) {
	for (int i = 0; i < this->artists.size(); i++) {
		if (*(this->getArtist(i)) == *oa) {
			delete this->artists[i];
			this->artists[i] = na->clone();
			this->saveToFile();
			return;
		}
	}
}

void Repo::UpdateU(User* ou, User* nu) {
	for (int i = 0; i < this->users.size(); i++) {
		if (*(this->getUser(i)) == *ou) {
			delete this->users[i];
			this->users[i] = nu->clone();
			this->saveToFile();
			return;
		}
	}
}

void Repo::DeleteM(Movie* m) {
	for (int i = 0; i < this->movies.size(); i++) {
		if (**(this->movies.begin() + i) == *m) {
			delete this->movies[i];
			this->movies.erase(this->movies.begin() + i);
			this->saveToFile();
			return;
		}
	}
}

void Repo::DeleteA(Artist* a) {
	for (int i = 0; i < this->artists.size(); i++) {
		if (**(this->artists.begin() + i) == *a) {
			delete this->artists[i];
			this->artists.erase(this->artists.begin() + i);
			this->saveToFile();
			return;
		}
	}
}

void Repo::DeleteU(User* u) {
	for (int i = 0; i < this->users.size(); i++) {
		if (**(this->users.begin() + i) == *u) {
			delete this->users[i];
			this->users.erase(this->users.begin() + i);
			this->saveToFile();
			return;
		}
	}
}

void Repo::emptyRepo() {
	for (int i = 0; i < this->getSizeM(); i++) {
		delete this->movies[i];
	}
	this->movies.clear();
	for (int i = 0; i < this->getSizeA(); i++) {
		delete this->artists[i];
	}
	this->artists.clear();
	for (int i = 0; i < this->getSizeU(); i++) {
		delete this->users[i];
	}
	this->users.clear();
}


#include "RepoFileCSV.h"
#include <fstream>

RepoFileCSV::RepoFileCSV() : Repo() {

}

RepoFileCSV::RepoFileCSV(string fileName, ValidationArtist* ValidateA) : Repo(fileName, ValidateA) {
	loadFromFile();
}

RepoFileCSV::~RepoFileCSV() {

}

void RepoFileCSV::loadFromFile() {
	ifstream f(this->fileName);
	if (f.is_open()) {
		this->emptyRepo();
		string line;
		string delim = ",";
		while (getline(f, line)) {
			if (line.substr(0, 1) == "M") {

				line = line.erase(0, 2);

				int pos = line.find(delim);
				string name = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				pos = line.find(delim);
				string date = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				pos = line.find(delim);
				string place = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				pos = line.find(delim);
				int placeAvailable = stoi(line.substr(0, pos));
				line = line.erase(0, pos + 1);

				pos = line.find(delim);
				int placeSold = stoi(line.substr(0, pos));
				line = line.erase(0, pos + 1);

				vector<string>actors;
				pos = line.find(delim);
				string actor = line.substr(0, pos);
				actors.push_back(actor);

				Movie* m = new Movie(name, actors, date, place, placeAvailable, placeSold);
				this->movies.push_back(m);
			}
			else if (line.substr(0, 1) == "A")
			{
				line = line.erase(0, 2);

				int pos = line.find(delim);
				string name = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				pos = line.find(delim);
				string date = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				pos = line.find(delim);
				string place = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				pos = line.find(delim);
				int placeAvailable = stoi(line.substr(0, pos));
				line = line.erase(0, pos + 1);

				pos = line.find(delim);
				int placeSold = stoi(line.substr(0, pos));

				Artist* a = new Artist(name, date, place, placeAvailable, placeSold);
				this->artists.push_back(a);
			}
			else if (line.substr(0, 1) == "U") {

				line = line.erase(0, 2);

				int pos = line.find(delim);
				string name = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				pos = line.find(delim);
				string password = line.substr(0, pos);

				User* u = new User(name, password);
				this->users.push_back(u);
			}
		}
		f.close();
	}
}

void RepoFileCSV::saveToFile() {
	ofstream f(this->fileName);
	if (f.is_open()) {
		for (Movie* m : this->movies) {
			f << m->toString(",") << endl;
		}
		for (Artist* a : this->artists) {
			f << a->toString(",") << endl;
		}
		for (User* u : this->users) {
			f << u->toString(",") << endl;
		}
	}
}

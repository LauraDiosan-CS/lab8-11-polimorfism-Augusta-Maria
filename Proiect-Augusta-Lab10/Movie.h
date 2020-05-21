#pragma once
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Movie
{
private:
	string name;
	vector <string> actorList;
	string date;
	string place;
	int placeAvailable;
	int placeSold;
public:
	Movie();
	Movie(string n, vector<string> a, string d, string p, int pa, int ps);
	Movie(const Movie& m);
	~Movie();

	Movie* clone();

	string getName();
	vector<string> getActorList();
	string getDate();
	string getPlace();
	int getPlaceAvailable();
	int getPlaceSold();

	void setName(string newValue);
	void setActorList(vector<string> newValue);
	void setDate(string newValue);
	void setPlace(string newValue);
	void setPA(int newValue);
	void setPS(int newValue);

	string vector_to_string(vector<string>actors, string delim);
	Movie& operator=(const Movie& m);
	bool operator==(const Movie& m);
	string toString(string delim);
};
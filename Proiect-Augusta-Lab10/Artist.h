#pragma once
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Artist {
private:
	string name;
	string date;
	string place;
	int placeAvailable;
	int placeSold;
public:
	Artist();
	Artist(string n, string d, string p, int pa, int ps);
	Artist(const Artist& a);
	~Artist();

	Artist* clone();

	string getName();
	string getDate();
	string getPlace();
	int getPlaceAvailable();
	int getPlaceSold();

	void setName(string newValue);
	void setDate(string newValue);
	void setPlace(string newValue);
	void setPA(int newValue);
	void setPS(int newValue);

	Artist& operator=(const Artist& a);
	bool operator==(const Artist& a);
	string toString(string delim);
};
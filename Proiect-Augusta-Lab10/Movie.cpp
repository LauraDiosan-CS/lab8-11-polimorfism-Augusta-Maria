#include "Movie.h"

Movie::Movie()
{
	this->name = "";
	this->actorList = {};
	this->date = "";
	this->place = "";
	this->placeAvailable = 0;
	this->placeSold = 0;
}

Movie::Movie(string n, vector<string> a, string d, string p, int pa, int ps)
{
	this->name = n;
	this->actorList = a;
	this->date = d;
	this->place = p;
	this->placeAvailable = pa;
	this->placeSold = ps;
}

Movie::Movie(const Movie& m)
{
	this->name = m.name;
	this->actorList = m.actorList;
	this->date = m.date;
	this->place = m.place;
	this->placeAvailable = m.placeAvailable;
	this->placeSold = m.placeSold;
}

Movie::~Movie()
{
}

Movie* Movie::clone()
{
	return new Movie(this->name, this->actorList, this->date, this->place, this->placeAvailable, this->placeSold);
}

string Movie::getName()
{
	return this->name;
}

vector<string> Movie::getActorList()
{
	return this->actorList;
}

string Movie::getDate()
{
	return this->date;
}

string Movie::getPlace()
{
	return this->place;
}

int Movie::getPlaceAvailable()
{
	return this->placeAvailable;
}

int Movie::getPlaceSold()
{
	return this->placeSold;
}

void Movie::setName(string newValue)
{
	this->name = newValue;
}

void Movie::setActorList(vector<string> newValue)
{
	this->actorList = newValue;
}

void Movie::setDate(string newValue)
{
	this->date = newValue;
}

void Movie::setPlace(string newValue)
{
	this->place = newValue;
}

void Movie::setPA(int newValue)
{
	this->placeAvailable = newValue;
}

void Movie::setPS(int newValue)
{
	this->placeSold = newValue;
}

string Movie::vector_to_string(vector<string>actors, string delim)
{
	string s;
	for (string actor : actors) {
		s += delim;
		s += actor;
	}
	return s;
}

Movie& Movie::operator=(const Movie& m)
{
	this->name = m.name;
	this->actorList = m.actorList;
	this->date = m.date;
	this->place = m.place;
	this->placeAvailable = m.placeAvailable;
	this->placeSold = m.placeSold;
	return *this;
}

bool Movie::operator==(const Movie& m)
{
	return (this->name == m.name) && (this->actorList == m.actorList) && (this->date == m.date) && (this->place == m.place) && (this->placeAvailable == m.placeAvailable) && (this->placeSold == m.placeSold);
}

string Movie::toString(string delim)
{
	string s = "M" + delim + this->name + vector_to_string(this->actorList, delim) + delim + this->date = delim + this->place + delim + to_string(this->placeAvailable) + delim + to_string(this->placeSold);
	return s;
}
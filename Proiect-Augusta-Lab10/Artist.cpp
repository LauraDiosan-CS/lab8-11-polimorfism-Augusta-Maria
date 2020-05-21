#include "Artist.h"

Artist::Artist()
{
	this->name = "";
	this->date = "";
	this->place = "";
	this->placeSold = 0;
	this->placeAvailable = 0;
}

Artist::Artist(string n, string d, string p, int pa, int ps)
{
	this->name = n;
	this->date = d;
	this->place = p;
	this->placeAvailable = pa;
	this->placeSold = ps;
}

Artist::Artist(const Artist& a)
{
	this->name = a.name;
	this->date = a.date;
	this->place = a.place;
	this->placeAvailable = a.placeAvailable;
	this->placeSold = a.placeSold;
}

Artist::~Artist()
{

}

Artist* Artist::clone()
{
	return new Artist(this->name, this->date, this->place, this->placeAvailable, this->placeSold);
}

string Artist::getName()
{
	return this->name;
}

string Artist::getDate()
{
	return this->date;
}

string Artist::getPlace()
{
	return this->place;
}

int Artist::getPlaceAvailable()
{
	return this->placeAvailable;
}

int Artist::getPlaceSold()
{
	return this->placeSold;
}

void Artist::setName(string newValue)
{
	this->name = newValue;
}

void Artist::setDate(string newValue)
{
	this->date = newValue;
}

void Artist::setPlace(string newValue)
{
	this->place = newValue;
}

void Artist::setPA(int newValue)
{
	this->placeAvailable = newValue;
}

void Artist::setPS(int newValue)
{
	this->placeSold = newValue;
}

Artist& Artist::operator=(const Artist& a)
{
	this->name = a.name;
	this->date = a.date;
	this->place = a.place;
	this->placeAvailable = a.placeAvailable;
	this->placeSold = a.placeSold;
	return *this;
}

bool Artist::operator==(const Artist& a)
{
	return (this->name == a.name) && (this->date == a.date) && (this->place == a.place) && (this->placeAvailable == a.placeAvailable) && (this->placeSold == a.placeSold);
}

string Artist::toString(string delim)
{
	string s = "A" + delim + this->name + delim + this->date = delim + this->place + delim + to_string(this->placeAvailable) + delim + to_string(this->placeSold);
	return s;
}
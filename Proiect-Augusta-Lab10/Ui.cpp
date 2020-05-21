#include <iostream>
#include "Ui.h"
using namespace std;

Ui::Ui() {
}

Ui::Ui(Service& s) {
	this->s = s;
}

Ui::~Ui() {
}

void Ui::Meniu() {
	cout << "  0.  Exit" << endl;
	cout << "  1.  Afisare filme" << endl;
	cout << "  2.  Afisare artisti" << endl;
	cout << "  3.  Cautare dupa data" << endl;
	cout << "  4.  Cumpara bilete " << endl;
	cout << "  5.  Adaugare artist" << endl;
}

void Ui::login() {
	bool goOn = false;
	while (!goOn)
	{
		string name;
		string password;
		cout << "Nume: ";
		cin >> name;
		cout << "Parola: ";
		cin >> password;
		int a = s.login(name, password);
		if (a == 0) {
			goOn = true;
		}
		else {
			cout << "Eroare!" << endl;
		}
	}
}

void Ui::printAllMovie()
{
	vector<Movie*> movies = s.printAllMovie();
	for (Movie* m : movies)
	{
		cout << m->getName() << " " << m->getActorList()[0] << " " << m->getDate() << " " << m->getPlace() << " " << m->getPlaceAvailable() << " " << m->getPlaceSold() << endl;
	}
}

void Ui::printAllArtist()
{
	vector<Artist*> artists = s.printAllArtist();
	for (Artist* a : artists)
	{
		cout << a->getName() << " " << a->getDate() << " " << a->getPlace() << " " << a->getPlaceAvailable() << " " << a->getPlaceSold() << endl;
	}
}

void Ui::AddA() {
	string name, date, place;
	int placeAvailable, placeSold;
	cout << "Insert the name: ";
	cin >> name;
	cout << "Insert the date: ";
	cin >> date;
	cout << "Insert the location: ";
	cin >> place;
	cout << "Insert the number of available places: ";
	cin >> placeAvailable;
	cout << "Insert the number of sold places: ";
	cin >> placeSold;
	try {
		Artist* a = new Artist(name, date, place, placeAvailable, placeSold);
		s.AddA(a);
		cout << endl;
		cout << "          |  Artist added!  | 		" << endl;
	}
	catch (MyException & exception) {
		cout << endl;
		cout << exception.getMessage() << endl;
	}
}

void Ui::findByDate()
{
	string date;
	cout << "Introduceti data:";
	cin >> date;
	vector<Movie*> movies = s.showMoviesByDate(date);
	vector<Artist*> artists = s.showArtistsByDate(date);
	for (Movie* m : movies)
	{
		cout << m->getName() << " " << m->getActorList()[0] << " " << m->getDate() << " " << m->getPlace() << " " << m->getPlaceAvailable() << " " << m->getPlaceSold() << endl;
	}
	for (Artist* a : artists)
	{
		cout << a->getName() << " " << a->getDate() << " " << a->getPlace() << " " << a->getPlaceAvailable() << " " << a->getPlaceSold() << endl;
	}

}

void Ui::buyTickets() {
	string name;
	int tickets;
	cout << "Introduceti nume:";
	cin >> name;
	cout << "Introduceti nr bilete:";
	cin >> tickets;
	int r = s.buyTickets(name, tickets);
	if (r == 0) {
		cout << "Cumparare esuata";

	}
	if (r == 1) {
		cout << "Cumparare reusita";
	}
}

void Ui::start()
{
	login();
	cout << "User succesfully logged in!" << endl << endl;
	printAllMovie();
	printAllArtist();
	int option;
	bool goOn = true;
	while (goOn)
	{
		Meniu();
		cout << "Optiune: ";
		cin >> option;
		if (option == 1)
		{
			printAllMovie();
		}
		if (option == 2)
		{
			printAllArtist();
		}
		if (option == 3)
		{
			findByDate();
		}
		if (option == 4) {
			buyTickets();
		}
		if (option == 5) {
			AddA();
		}
		if (option == 0)
		{
			goOn = false;
		}
	}
}

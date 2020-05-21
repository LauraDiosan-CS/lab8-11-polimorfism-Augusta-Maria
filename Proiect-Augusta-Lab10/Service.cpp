#include "Service.h"

Service::Service() {
	r = NULL;
	ValidateA = NULL;
}

Service::Service(Repo* r, ValidationArtist* ValidateA) {
	this->r = r;
	this->ValidateA = ValidateA;
}

Service::~Service() {

}

int Service::login(string user, string password) {
	vector<User*> users = r->getAllU();
	User* n = new User(user, password);
	for (User* u : users) {
		if (*u == *n) {
			return 0;
		}
	}
	return -1;
}

vector<Movie*> Service::printAllMovie() {
	return r->getAllM();
}

vector<Artist*> Service::printAllArtist() {
	return r->getAllA();
}

vector<Movie*> Service::showMoviesByDate(string date)
{
	vector<Movie*> found;
	for (Movie* m : r->getAllM())
	{
		if (m->getDate() == date)
			found.push_back(m);
	}
	return found;
}

vector<Artist*> Service::showArtistsByDate(string date)
{
	vector<Artist*> found;
	for (Artist* a : r->getAllA())
	{
		if (a->getDate() == date)
			found.push_back(a);
	}
	return found;
}

int Service::buyTickets(string name, int tickets) {
	for (Movie* m : r->getAllM()) {
		if (m->getName() == name && m->getPlaceAvailable() > tickets) {
			Movie* mn = new Movie(name, m->getActorList(), m->getDate(), m->getPlace(), m->getPlaceAvailable() - tickets, m->getPlaceSold() + tickets);
			r->UpdateM(m, mn);
			return 1;
		}
	}
	for (Artist* a : r->getAllA()) {
		if (a->getName() == name && a->getPlaceAvailable() > tickets) {
			Artist* an = new Artist(name, a->getDate(), a->getPlace(), a->getPlaceAvailable() - tickets, a->getPlaceSold() + tickets);
			r->UpdateA(a, an);
			return 1;
		}
	}
	return 0;

}

void Service::AddA(Artist* a) {
	try {
		r->AddA(a);
	}
	catch (ValidationException & exception) {
		throw MyException("Add failed! " + exception.Reason());
	}
}
#pragma once
#include "Repo.h"
#include "Artist.h"
#include "Movie.h"
#include "User.h"
#include "ValidationArtist.h"
#include "ValidationException.h"
#include "MyException.h"

class Service {
private:
	Repo* r;
	ValidationArtist* ValidateA;
public:
	Service();
	Service(Repo* r, ValidationArtist* ValidateA);
	~Service();

	void AddA(Artist* a);
	int buyTickets(string name, int tickets);
	vector<Movie*> showMoviesByDate(string date);
	vector<Artist*> showArtistsByDate(string date);
	int login(string user, string password);

	vector<Movie*> printAllMovie();
	vector<Artist*> printAllArtist();
};


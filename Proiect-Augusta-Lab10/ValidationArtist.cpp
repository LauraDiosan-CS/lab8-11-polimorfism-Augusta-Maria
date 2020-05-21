#include "ValidationArtist.h"

ValidationArtist::ValidationArtist()
{
	errors = 0;
}

ValidationArtist::~ValidationArtist()
{
}

int ValidationArtist::Validate(Artist* a)
{
	errors = 0;
	if (a->getName() == " ") {
		errors++;
		message += " Name can not be null! ";
	}
	if (a->getDate() == " ") {
		errors++;
		message += " Date can not be null! ";
	}
	if (a->getPlace() == " ") {
		errors++;
		message += " Location can not be null! ";
	}
	if (a->getPlaceAvailable() < 0) {
		errors++;
		message += " The number of available places can not be 0 or smaller! ";
	}
	if (a->getPlaceSold() < 0) {
		errors++;
		message += " The number of sold places can not be below 0! ";
	}
	return errors;
}

string ValidationArtist::toString() {
	return message;
}
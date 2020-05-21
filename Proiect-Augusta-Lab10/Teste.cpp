#include "Teste.h"

#include <cassert>

void testMovie()
{
	Movie m1;
	Movie m3;
	assert(m1.getName() == "");
	Movie m2("Titanic", { "Leo","Kate" }, "10.05.2019", "Manastur", 100, 150);
	assert(m2.getDate() == "10.05.2019");
	assert(m2.getPlaceAvailable() == 100);
	m2.setName("Alisia");
	m2.setDate("12.02.2020");
	m2.setPlace("Colibita");
	assert(m2.getPlace() == "Colibita");
}

void testArtist()
{
	Artist a1;
	assert(a1.getPlaceAvailable() == 0);
	Artist a2("Fuego", "25.12.2018", "Sala Palatului", 1, 499);
	assert(a2.getPlaceAvailable() == 1);
	assert(a2.getPlace() == "Sala Palatului");
	a2.setDate("12.12.2012");
	a2.setPA(17);
	assert(a2.getPlaceAvailable() == 17);
}

void testUser() {
	User u1("Augusta", "1234");
	User u2("Ioana", "2345");
	assert(u1.getName() == "Augusta");
	u2.setPassword("1111");
	assert(u2.getPassword() == "1111");

}

void testRepo(Repo* r)
{
	vector<string>actori = { "Luana" };
	Artist* a1 = new Artist("Fuego", "25.12.2018", "Sala Palatului", 1, 499);
	r->AddA(a1);
	assert(r->getSizeA() == 1);
	Artist* a2 = new Artist("Martin_Garrix", "13.13.2013", "Tomorrowland", 10000, 10000);
	r->AddA(a2);
	r->DeleteA(a1);
	assert(r->getSizeA() == 1);
}



void testService(Repo* r) {
	ValidationArtist* ValidateA = new ValidationArtist();
	Service S(r, ValidateA);
	User* u1 = new User("Danuta", "2345");
	assert(S.login("Danuta", "2345"));

}


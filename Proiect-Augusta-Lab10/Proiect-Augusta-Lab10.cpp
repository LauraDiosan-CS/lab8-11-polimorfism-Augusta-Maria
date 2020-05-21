#include <iostream>
#include <string>
#include <vector>
#include "Repo.h"
#include "RepoFileCSV.h"
#include "RepoFileTXT.h"
#include "Service.h"
#include "UI.h"
#include "Teste.h"
#include "ValidationArtist.h"
#include "MyException.h"

using namespace std;

int main() {
    testUser();
    testMovie();
    testArtist();
    ValidationArtist* ValidateA = new ValidationArtist();
    MyException Exception();
    Repo* TXT = new RepoFileTXT("Tests.txt", ValidateA);
    Repo* CSV = new RepoFileCSV("Tests.csv", ValidateA);
    testRepo(TXT);
    testRepo(CSV);
    testService(TXT);
    testService(CSV);
    Repo* r;
    string tip;
    cout << "TXT SAU CSV?";
    cin >> tip;
    if (tip == "txt") {
        r = new RepoFileTXT("Date.txt", ValidateA);
        Service s(r, ValidateA);
        Ui Ui(s);
        Ui.start();
    }
    if (tip == "csv") {
        r = new RepoFileCSV("Date.csv", ValidateA);
        Service s(r, ValidateA);
        Ui Ui(s);
        Ui.start();
    }
    else {
        cout << endl;
        cout << "Eroare!" << endl;
    }
    return 0;

}

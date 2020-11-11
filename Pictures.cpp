//
// Created by Bruce Tieu on 11/10/20.
//
#include <iostream>
#include <fstream>
#include <string>
#include "Pictures.h"
#include "Database.h"

using namespace std;

string Pictures::getNominations() {return nominations;}
string Pictures::getRating() {return rating;}
string Pictures::getDuration() {return duration;}
string Pictures::getGenre1() {return genre1;}
string Pictures::getGenre2() {return genre2;}
string Pictures::getMetacritic() {return metacritic;}
string Pictures::getSynopsis() {return synopsis;}

/**
 * Read in "pictures.csv" file.
 */
void Pictures::readInFile() {
    ifstream infile("pictures.csv");

    int records = 0;

    getline(infile, header);

    while (infile.peek() != EOF) {
        getline(infile, name, ',');
        getline(infile, year, ',');
        getline(infile, nominations, ',');
        getline(infile, rating, ',');
        getline(infile, duration, ',');
        getline(infile, genre1, ',');
        getline(infile, genre2, ',');
        getline(infile, metacritic, ',');
        getline(infile, synopsis);
        cout << name << endl << year << endl << nominations << endl << rating << endl << duration << endl << genre1
             << endl << genre2 << endl << metacritic << endl << synopsis << endl;
        records++;
        cout << "RECORDS: " << records << endl << endl;
    }
}

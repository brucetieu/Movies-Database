//
// Created by Bruce Tieu on 11/10/20.
//
#include <iostream>
#include <fstream>
#include <string>
#include "ActorsActresses.h"
#include "Database.h"

using namespace std;

string ActorsActresses::getAward() {return award;}
string ActorsActresses::getWinner() {return winner;}
string ActorsActresses::getFilm() {return film;}

/**
 * Read in "actor-actresses.csv".
 */
void ActorsActresses::readInFile() {
    ifstream infile("actor-actress.csv");

    int records = 0;

    getline(infile, header);

    while (infile.good()) {
        getline(infile, year, ',');
        getline(infile, award, ',');
        getline(infile, winner, ',');
        getline(infile, name, ',');
        getline(infile, film);
        cout << year << endl << award << endl << winner << endl << name << endl << film << endl;
        records++;
        cout << "RECORDS: " << records << endl << endl;
    }

    cout << "Records: " << records << endl;
}
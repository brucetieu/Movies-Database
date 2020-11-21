//
// Created by Bruce Tieu on 11/10/20.
//
#include <iostream>
#include <fstream>
#include <string>

//#include "ActorsBST.h"
#include "ActorsActresses.h"
#include "BinaryTree.h"

using namespace std;

ActorsActresses::ActorsActresses() {
    tree = new BinaryTree<ActorsActresses>();

}
ActorsActresses::ActorsActresses(string year, string award, string winner, string name,
                                 string film) {
    this->year = year;
    this->award = award;
    this->winner = winner;
    this->name = name;
    this->film = film;
}

void ActorsActresses::setYear(std::string year) { this->year = year; }
void ActorsActresses::setAward(string award) { this->award = award; }
void ActorsActresses::setWinner(string winner) { this->winner = winner; }
void ActorsActresses::setName(std::string name) { this->name = name; }
void ActorsActresses::setFilm(string film) { this->film = film; }

string ActorsActresses::getYear() const { return year; }
string ActorsActresses::getAward() const {return award;}
string ActorsActresses::getWinner() const {return winner;}
string ActorsActresses::getName() const {return name; }
string ActorsActresses::getFilm() const {return film;}

bool ActorsActresses::operator<(const ActorsActresses &right) {
    return name < right.getName();
}

bool ActorsActresses::operator>(const ActorsActresses &right) {
    return name > right.getName();
}

bool ActorsActresses::operator==(const ActorsActresses &right) {
    return name == right.getName();
}

bool ActorsActresses::operator>=(const ActorsActresses &right) {
    return name >= right.getName();
}

ostream& operator << (ostream &output, const ActorsActresses &actor) {
    output << actor.getYear() << endl;
    output << actor.getAward() << endl;
    output << actor.getWinner() << endl;
    output << actor.getName() << endl;
    output << actor.getFilm() << endl;
    return output;
}



/**
 * Read in "actor-actresses.csv".
 */
void ActorsActresses::readInFile() {

    string header;

    ifstream infile("actor-actress.csv");

    if (infile.fail()) {
        cerr << "Error reading file" << endl;
    }

    else {
        int records = 0;

        getline(infile, header);

        while (infile.peek() != EOF) {

            getline(infile, year, ',');
            getline(infile, award, ',');
            getline(infile, winner, ',');
            getline(infile, name, ',');
            getline(infile, film, '\n');

            tree->insert(ActorsActresses(year, award, winner, name, film));
            records++;
        }
    }
    tree->inorderPrint();
    cout << "File successfully read" << endl;
}

void ActorsActresses::addARecord(string year, string award, string winner, string name, string film) {

    tree->insert(ActorsActresses(year, award, winner, name, film));
    cout << "Record successfully inserted!" << endl;
    tree->inorderPrint();
}



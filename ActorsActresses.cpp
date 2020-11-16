//
// Created by Bruce Tieu on 11/10/20.
//
#include <iostream>
#include <fstream>
#include <string>
#include "ActorsBST.h"
#include "Database.h"

using namespace std;

ActorsActresses::ActorsActresses() {
////    root = nullptr;
}
ActorsActresses::ActorsActresses(string name, string year, string award, string winner,
                                 string film) {
    this->name = name;
    this->year = year;
    this->award = award;
    this->winner = winner;
    this->film = film;
}

//void ActorsActresses::setAward(string award) { this->award = award; }
//void ActorsActresses::setWinner(string winner) { this->winner = winner; }
//void ActorsActresses::setFilm(string film) { this->film = film; }
//
//string ActorsActresses::getAward() {return award;}
//string ActorsActresses::getWinner() {return winner;}
//string ActorsActresses::getFilm() {return film;}

/**
 * Read in "actor-actresses.csv".
 */
void ActorsActresses::readInFile() {

    ActorsActresses actorsActresses;

    ActorsBST *actorsBst = new ActorsBST();
    ActorsBST::BstNode *root = new ActorsBST::BstNode();

    ifstream infile("actor-actress.csv");

    int records = 0;

    getline(infile, header);

    while (infile.peek() != EOF) {

        getline(infile, actorsActresses.year, ',');
        getline(infile, actorsActresses.award, ',');
        getline(infile, actorsActresses.winner, ',');
        getline(infile, actorsActresses.name, ',');
        getline(infile, actorsActresses.film, '\n');

        root = actorsBst->insert(root, actorsActresses);
//        cout << year << endl << award << endl << winner << endl << name << endl << film << endl;
        records++;
//        cout << "RECORDS: " << records << endl << endl;
    }
    actorsBst->inorderTraversal(root);
}
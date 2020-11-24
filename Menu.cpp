//
// Created by Bruce Tieu on 11/21/20.
//

#include "Menu.h"
#include "ActorsActresses.h"
#include <iostream>

using namespace std;

Menu::Menu() {
    actorsActresses = new ActorsActresses();
}
void Menu::mainMenu() {
    cout << "--------------------Main Menu-------------------------" << endl;
    cout << "a. Read in a file" << endl;
    cout << "b. Add a record" << endl;
    cout << "c. Search a record" << endl;
    cout << "q. Quit" << endl;

    bool good = true;

    char choice;
    cin >> choice;

    while (good) {
        switch (choice) {
            case 'a':
                subMenuForA();
                break;

            case 'b':
                subMenuForB();
                break;

            case 'c':
                subMenuForC();
                break;

            case 'q':
                good = false;
                break;
            default:
                good = false;
                break;
        }
    }
}

void Menu::subMenuForA() {
    cout << "Choose the database to read the file into." << endl;
    cout << "1. Actors Actresses Database" << endl;
    cout << "2. Pictures Database" << endl;
    cout << "3. Quit" << endl;

    bool good = true;
    int choice;
    cin >> choice;

    while (good) {
        switch(choice) {
            case 1: {
                actorsActresses->readInFile();
                mainMenu();
                break;
            }

            case 3:
                good = false;
                break;

            default:
                break;
        }
    }
}

void Menu::subMenuForB() {
    cout << "Choose which database you want to add a record in." << endl;
    cout << "1. Actors Actresses Database" << endl;
    cout << "2. Pictures Database" << endl;
    cout << "3. Quit" << endl;

    bool good = true;
    int choice;
    cin >> choice;

    while (good) {
        switch (choice) {
            case 1:
                subMenuAddRecordInActors();
                mainMenu();
                break;

            case 3:
                good = false;
                break;

            default:
                break;
        }
    }
}

void Menu::subMenuAddRecordInActors() {
    string year, award, winner, name, film;

    cout << "Insert Year: ";
    cin >> year;
    cout << "Insert Award: ";
    cin >> award;
    cout << "Insert Winner: ";
    cin >> winner;
    cout << "Insert Name: ";
    cin >> name;
    cout << "Insert Film: ";
    cin >> film;
    cout << "\n";

    actorsActresses->addARecord(year, award, winner, name, film);
}

void Menu::subMenuForC() {
    cout << "Choose which database you want to search for a record in." << endl;
    cout << "1. Actors Actresses Database" << endl;
    cout << "2. Pictures Database" << endl;
    cout << "3. Quit" << endl;

    bool good = true;
    int choice;
    cin >> choice;

    while (good) {
        switch (choice) {
            case 1:
                subMenuSearchRecordInActors();
                break;

            case 3:
                good = false;
                break;

            default:
                break;
        }
    }

}

void Menu::subMenuSearchRecordInActors() {
    cout << "Choose a search option." << endl;
    cout << "a. Partial search on a field." << endl;
    cout << "b. Exact search on a field." << endl;
    cout << "d. Quit" << endl;

    bool good = true;
    char choice;
    cin >> choice;

    while (good) {
        switch (choice) {
            case 'a':
                partialSearchActors();
                break;
            case 'b':
                exactSearchActors();
                break;
            case 'c':
                good = false;
                exit(1);
            default:
                good = false;
                break;
        }
    }
}

void Menu::partialSearchActors() {
    cout << "Choose a field you'd like to partially search for." << endl;
    cout << "a. Award" << endl;
    cout << "b. Name" << endl;
    cout << "c. Film" << endl;
    cout << "d. Quit" << endl;

    char choice;
    bool good = true;
    cin >> choice;
    cin.ignore();

    while (good) {
        switch (choice) {
            case 'a':
                partialSearchAwardActors();
                exit(1);
                break;
            case 'b':
                partialSearchNameActors();
                break;
            case 'c':
                partialSearchFilmActors();
                break;
            case 'd':
                good = false;
                break;
            default:
                good = false;
                break;
        }
    }
}

void Menu::exactSearchActors() {
    cout << "Choose a field you'd like to exactly search for." << endl;
    cout << "a. Award" << endl;
    cout << "b. Name" << endl;
    cout << "c. Film" << endl;
    cout << "d. Quit" << endl;

    char choice;
    bool good = true;
    cin >> choice;
    cin.ignore();

    while (good) {
        switch (choice) {
            case 'a':
                exactSearchAwardActors();
                exit(1);
                break;
            case 'b':
                exactSearchNameActors();
                break;
            case 'c':
                exactSearchFilmActors();
                break;
            case 'd':
                good = false;
                break;
            default:
                good = false;
                break;
        }
    }
}

void Menu::partialSearchAwardActors() {
    cout << "Enter a keyword to partially search for in the Awards field: " << endl;

    string field = "award";
    string awardKeyword;
    getline(cin, awardKeyword);

    actorsActresses->partialFindByAward(field, awardKeyword);
}

void Menu::partialSearchNameActors() {
    cout << "Enter a keyword to partially search for in the Name field: " << endl;

    string field = "name";
    string nameKeyword;
    getline(cin, nameKeyword);

    actorsActresses->partialFindByName(field, nameKeyword);
}

void Menu::partialSearchFilmActors() {
    cout << "Enter a keyword to partially search for in the Film field: " << endl;

    string field = "film";
    string filmKeyword;
    getline(cin, filmKeyword);

    actorsActresses->partialFindByFilm(field, filmKeyword);
}

void Menu::exactSearchAwardActors() {
    cout << "Enter a keyword to exactly search for in the Award field: " << endl;

    string field = "award";
    string awardMatch;
    getline(cin, awardMatch);

    actorsActresses->exactFindByAward(field, awardMatch);
}

void Menu::exactSearchNameActors() {
    cout << "Enter a keyword to exactly search for in the Name field: " << endl;

    string field = "name";
    string nameMatch;
    getline(cin, nameMatch);

    actorsActresses->exactFindByName(field, nameMatch);
}

void Menu::exactSearchFilmActors() {
    cout << "Enter a keyword to exactly search for in the Film field: " << endl;

    string field = "film";
    string filmMatch;
    getline(cin, filmMatch);

    actorsActresses->exactFindByFilm(field, filmMatch);
}
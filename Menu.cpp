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
    cout << "a. Partial search" << endl;
    cout << "b. Exact search" << endl;
    cout << "c. Quit" << endl;

    bool good = true;
    char choice;
    cin >> choice;

    while (good) {
        switch (choice) {
            case 'a':
                partialSearchActors();
                break;
            case 'b':
//                exactSearchActors();
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

                break;
            case 'c':
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
    cout << "Enter a keyword to partially search for in the awards field: " << endl;

    string field = "award";
    string awardKeyword;
    getline(cin, awardKeyword);

    actorsActresses->partialSearchAField(field, awardKeyword);
}
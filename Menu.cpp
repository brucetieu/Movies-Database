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

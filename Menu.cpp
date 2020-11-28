//
// Created by Bruce Tieu on 11/21/20.
//

#include "Menu.h"
#include "ActorsActresses.h"
#include "BinaryTree.h"
#include <vector>
#include <iostream>

using namespace std;

/**
 * Initialize ActorsActresses object within the default constructor.
 */
Menu::Menu() {
    // Dynamically create a new ActorsActresses object.
    actorsActresses = new ActorsActresses();
}

/**
 * Display the main menu.
 */
void Menu::mainMenu() {
    cout << "=====================Main Menu=========================" << endl;
    cout << "a. Read in a file" << endl;
    cout << "b. Add a record" << endl;
    cout << "c. Search a record" << endl;
    cout << "q. Quit" << endl;
    cout << "=======================================================" << endl;

    bool good = true;

    char choice;
    cin >> choice;

    while (good) {
        switch (choice) {
            case 'a':
                subMenuForA(); // Submenu for a. Read in File.
                break;

            case 'b':
                subMenuForB(); // Submenu for b. Add a record.
                break;

            case 'c':
                subMenuForC(); // Submenu for c. Search a record.
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

/**
 * Create submenu for reading in file.
 */
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
                // Store each record in the BST, each represents a node. We start at the root.
                root = actorsActresses->readInFile();
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

/**
 * Create submenu for choosing which database to add a record to.
 */
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
                subMenuAddRecordInActors(); // Display submenu for adding records to a database.
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

/**
 * Create the submenu for adding records into the ActorsActresses db.
 */
void Menu::subMenuAddRecordInActors() {
    string year, award, winner, name, film;

    /// Prompt user to enter something for each field to be added as 1 record.
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

    // Add this record to the BST.
    actorsActresses->addARecord(year, award, winner, name, film);
}

/**
 * Create the submenu for searching a record.
 */
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
                subMenuSearchRecordInActors(); // Display the submenu which lets user choose partial or exact search.
                break;

            case 3:
                good = false;
                break;

            default:
                break;
        }
    }

}

/**
 * Create the submenu for partial / exact searches on a record.
 */
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
                partialSearchActors(); // Display submenu which lets user select which fields they'd like to partially search for.
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

/**
 * Create the menu which allows a user to choose a field in a db they'd like to search for.
 */
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

            // Partial search on Award field.
            case 'a':

                // The new root will be the BST which contains all the results returned from the partial search.
                root = partialSearchActorsField(ActorsActresses::AWARD);

                // Display the menu which prompts a user to search again within the existing search results, or perform a new search.
                afterSearchActors();
                good = false;
                break;

            // Partial search on Name field.
            case 'b':
                root = partialSearchActorsField(ActorsActresses::NAME);
                afterSearchActors();
                break;

            // Partial search on Name field.
            case 'c':
                root = partialSearchActorsField(ActorsActresses::FILM);
                afterSearchActors();
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
    cout << "a. Year" << endl;
    cout << "b. Award" << endl;
    cout << "c. Winner" << endl;
    cout << "d. Name" << endl;
    cout << "e. Film" << endl;
    cout << "f. Quit" << endl;

    char choice;
    bool good = true;
    cin >> choice;
    cin.ignore();

    while (good) {
        switch (choice) {
            case 'a':
                root = exactSearchActorsField(ActorsActresses::YEAR);
                afterSearchActors();
                break;
            case 'b':
                root = exactSearchActorsField(ActorsActresses::AWARD);
                afterSearchActors();
                break;
            case 'c':
                root = exactSearchActorsField(ActorsActresses::WINNER);
                afterSearchActors();
                break;
            case 'd':
                root = exactSearchActorsField(ActorsActresses::NAME);
                afterSearchActors();
                break;
            case 'e':
                root = exactSearchActorsField(ActorsActresses::FILM);
                afterSearchActors();
                break;
            case 'f':
                exit(1);
            default:
                good = false;
                break;
        }
    }
}

/**
 * Perform a partial search on any given field.
 * @param field The specific field (Award, Name, or Film).
 * @return The updated root with all results from the partial search. Overwrite the original root which contained all records from CSV.
 */
BinaryTree<ActorsActresses>::TreeNode* Menu::partialSearchActorsField(std::string &field) {
    cout << "Enter a keyword to partially search for in " << field << " field: ";

    string fieldKeyword;
    getline(cin, fieldKeyword);

    // tempRoot is the new root which stores all nodes from the partial search.
    BinaryTree<ActorsActresses>::TreeNode* tempRoot = actorsActresses->partialFindByField(field, fieldKeyword, root);

    return tempRoot; // Contains all the results from our partial search.
}

BinaryTree<ActorsActresses>::TreeNode* Menu::exactSearchActorsField(std::string &field) {
    cout << "Enter a keyword to exactly search for in " << field << " field: ";

    string fieldKeyword;
    getline(cin, fieldKeyword);

    // tempRoot is the new root which stores all nodes from the exact search, if any.
    BinaryTree<ActorsActresses>::TreeNode* tempRoot = actorsActresses->exactFindByField(field, fieldKeyword, root);

    return tempRoot;
}

/**
 * Create the menu to prompt user to perform a secondary search, or start over.
 */
void Menu::afterSearchActors() {
    cout << "a. Search within these results?" << endl;
    cout << "b. Start a new search?" << endl;
    cout << "c. Quit" << endl;

    char choice;
    bool good = true;
    cin >> choice;
    cin.ignore();

    while (good) {
        switch (choice) {
            case 'a':
                subMenuSearchRecordInActors(); // Bring the user back to the menu to choose a partial search or exact search.
                break;
            case 'b':
                // Reset the root to the BST with original data.
                root = actorsActresses->readInFile();
                subMenuSearchRecordInActors();
                break;
            case 'c':
                exit(1);
            default:
                good = false;
                break;
        }
    }
}


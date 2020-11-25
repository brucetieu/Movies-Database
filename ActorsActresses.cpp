//
// Created by Bruce Tieu on 11/10/20.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//#include "ActorsBST.h"
#include "ActorsActresses.h"
#include "BinaryTree.h"

using namespace std;

string ActorsActresses::YEAR = "year";
string ActorsActresses::AWARD = "award";
string ActorsActresses::WINNER = "winner";
string ActorsActresses::NAME = "name";
string ActorsActresses::FILM = "film";

/**
 * Default constructor which initializes an Binary Tree of type ActorsActresses.
 */
ActorsActresses::ActorsActresses() {
    actorsTree = new BinaryTree<ActorsActresses>();
    record = 0;
}

/**
 * Parameterized constructor to initialize member variables in Actors Actresses.
 * @param year The year of the film.
 * @param award The person who received the award (leading role, supporting role, etc).
 * @param winner If the film won (0 or 1).
 * @param name The name of the actor / actress.
 * @param film The name of the film.
 */
ActorsActresses::ActorsActresses(string year, string award, string winner, string name,
                                 string film) {
    this->year = year;
    this->award = award;
    this->winner = winner;
    this->name = name;
    this->film = film;
}

// Setters - Encapsulation.
void ActorsActresses::setYear(std::string year) { this->year = year; }
void ActorsActresses::setAward(string award) { this->award = award; }
void ActorsActresses::setWinner(string winner) { this->winner = winner; }
void ActorsActresses::setName(std::string name) { this->name = name; }
void ActorsActresses::setFilm(string film) { this->film = film; }

// Getters - Encapsulation.
string ActorsActresses::getYear() const { return year; }
string ActorsActresses::getAward() const {return award;}
string ActorsActresses::getWinner() const {return winner;}
string ActorsActresses::getName() const {return name; }
string ActorsActresses::getFilm() const {return film;}

/**
 * Overload the '<' operator to compare objects by the Name field.
 * @param right The ActorsActresses object.
 * @return True, if the comparison is true for each record, false otherwise.
 */
bool ActorsActresses::operator<(const ActorsActresses &right) {
    return name < right.getName();
}

/**
 * Overload the '>' operator to compare objects by Name field.
 * @param right The ActorsActresses Object passed in.
 * @return True, if the comparison is true, false otherwise.
 */
bool ActorsActresses::operator>(const ActorsActresses &right) {
    return name > right.getName();
}

/**
 * Overload the '==' operator to see if objects are equal by the Name.
 * @param right The ActorsActresses object being passed in.
 * @return True, if the comparison is true, false otherwise.
 */
bool ActorsActresses::operator==(const ActorsActresses &right) {
    return name == right.getName();
}

/**
 * Overload the '>=' operator to compare objects by Name.
 * @param right The ActorsActresses object being passed in.
 * @return True, if the comparison is true.
 */
bool ActorsActresses::operator>=(const ActorsActresses &right) {
    return name >= right.getName();
}

/**
 * Overload the '<<' operator to print out objects directly.
 * @param output The ostream object.
 * @param actor The ActorsActresses object.
 * @return The output stream.
 */
ostream& operator << (ostream &output, const ActorsActresses &actor) {
    output << actor.getYear() << endl;
    output << actor.getAward() << endl;
    output << actor.getWinner() << endl;
    output << actor.getName() << endl;
    output << actor.getFilm() << endl;
    return output;
}


/**
 * Read in "actor-actresses.csv" into a BST.
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

            // Insert each ActorsActresses object into the BST.
            actorsTree->insert(ActorsActresses(year, award, winner, name, film));
            records++;
        }
    }

    // Print out the contents in order by Name field.
    actorsTree->inorderPrint();
    cout << "File successfully read" << endl;
}

/**
 * Add a record to the ActorsActresses database.
 * @param year The year of the film.
 * @param award The person who received the award (leading role, supporting role, etc).
 * @param winner If the film won (0 or 1).
 * @param name The name of the actor / actress.
 * @param film The name of the film.
 */
void ActorsActresses::addARecord(string year, string award, string winner, string name, string film) {

    actorsTree->insert(ActorsActresses(year, award, winner, name, film));
    cout << "Record successfully inserted!" << endl;
    actorsTree->inorderPrint();
}

void ActorsActresses::partialFindByField(std::string &field, std::string &fieldKeyword) {
    root = actorsTree->getRoot();

    if (field == ActorsActresses::AWARD) {
        _inOrderTraversalPS(field, fieldKeyword, root);
    } else if (field == ActorsActresses::NAME) {
        _inOrderTraversalPS(field, fieldKeyword, root);
    } else if (field == ActorsActresses::FILM) {
        _inOrderTraversalPS(field, fieldKeyword, root);
    }
}

void ActorsActresses::_inOrderTraversalPS(std::string field, std::string fieldKeyword, BinaryTree<ActorsActresses>::TreeNode* root) {
    vector<BinaryTree<ActorsActresses>::TreeNode*> vecOfTreeNodes;

    if (root != nullptr) {
        if (field == ActorsActresses::AWARD) {
            _inOrderTraversalPS(field, fieldKeyword, root->right);
            if (root->data.getAward().find(fieldKeyword) != string::npos) vecOfTreeNodes.push_back(root);
            _inOrderTraversalPS(field, fieldKeyword, root->left);
        }
        else if (field == ActorsActresses::NAME) {
            _inOrderTraversalPS(field, fieldKeyword, root->right);
            if (root->data.getName().find(fieldKeyword) != string::npos) vecOfTreeNodes.push_back(root);
            _inOrderTraversalPS(field, fieldKeyword, root->left);
        }
        else if (field == ActorsActresses::FILM) {
            _inOrderTraversalPS(field, fieldKeyword, root->right);
            if (root->data.getFilm().find(fieldKeyword) != string::npos) vecOfTreeNodes.push_back(root);
            _inOrderTraversalPS(field, fieldKeyword, root->left);
        }
    }

    // Print out the records which contain a specific keyword from a field.
    for (int i = 0; i < vecOfTreeNodes.size(); i++) {
        cout << vecOfTreeNodes[i]->data << endl;
    }
}

void ActorsActresses::exactFindByField(std::string &field, std::string &fieldKeyword) {
    root = actorsTree->getRoot();

    if (field == ActorsActresses::YEAR) {
        _inOrderTraversalES(field, fieldKeyword, root);
    } else if (field == ActorsActresses::AWARD) {
        _inOrderTraversalES(field, fieldKeyword, root);
    } else if (field == ActorsActresses::WINNER){
        _inOrderTraversalES(field, fieldKeyword, root);
    } else if (field == ActorsActresses::NAME) {
        _inOrderTraversalES(field, fieldKeyword, root);
    } else if (field == ActorsActresses::FILM) {
        _inOrderTraversalES(field, fieldKeyword, root);
    }
}

void ActorsActresses::_inOrderTraversalES(std::string field, std::string fieldKeyword,
                                          BinaryTree<ActorsActresses>::TreeNode *root) {
    vector<BinaryTree<ActorsActresses>::TreeNode*> vecOfTreeNodes;

    if (root != nullptr) {
        if (field == ActorsActresses::YEAR) {
            _inOrderTraversalES(field, fieldKeyword, root->right);
            if (root->data.getYear() == fieldKeyword) vecOfTreeNodes.push_back(root);
            _inOrderTraversalES(field, fieldKeyword, root->left);
        }
        else if (field == ActorsActresses::AWARD) {
            _inOrderTraversalES(field, fieldKeyword, root->right);
            if (root->data.getAward() == fieldKeyword) vecOfTreeNodes.push_back(root);
            _inOrderTraversalES(field, fieldKeyword, root->left);
        }
        else if (field == ActorsActresses::NAME) {
            _inOrderTraversalES(field, fieldKeyword, root->right);
            if (root->data.getName() == fieldKeyword) vecOfTreeNodes.push_back(root);
            _inOrderTraversalES(field, fieldKeyword, root->left);
        }
        else if (field == ActorsActresses::WINNER) {
            _inOrderTraversalES(field, fieldKeyword, root->right);
            if (root->data.getWinner() == fieldKeyword) vecOfTreeNodes.push_back(root);
            _inOrderTraversalES(field, fieldKeyword, root->left);
        }
        else if (field == ActorsActresses::FILM) {
            _inOrderTraversalPS(field, fieldKeyword, root->right);
            if (root->data.getFilm() == fieldKeyword) vecOfTreeNodes.push_back(root);
            _inOrderTraversalPS(field, fieldKeyword, root->left);
        }
    }

    // Print out the records which contain a specific keyword from a field.
    for (int i = 0; i < vecOfTreeNodes.size(); i++) {
        cout << vecOfTreeNodes[i]->data << endl;
    }
}








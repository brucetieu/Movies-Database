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

string ActorsActresses::AWARD = "award";
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
//        bool hasAwardKeyword = root->data.getAward().find(fieldKeyword) != string::npos;
        _inOrderTraversal(field, fieldKeyword, root);
    }
//    else if (field == ActorsActresses::NAME) {
//        bool hasNameKeyword = root->data.getName().find(fieldKeyword) != string::npos;
//        _inOrderTraversal(field, fieldKeyword, root, hasNameKeyword);
//    } else if (field == ActorsActresses::FILM) {
//        bool hasFilmKeyword = root->data.getFilm().find(fieldKeyword) != string::npos;
//        _inOrderTraversal(field, fieldKeyword, root, hasFilmKeyword);
//    }
}

void ActorsActresses::_inOrderTraversal(std::string field, std::string fieldKeyword, BinaryTree<ActorsActresses>::TreeNode* root) {
    vector<BinaryTree<ActorsActresses>::TreeNode*> vecOfTreeNodes;
    
    if (root != nullptr) {
        if (field == ActorsActresses::AWARD) {
//        if (root != nullptr) {
            _inOrderTraversal(field, fieldKeyword, root->right);
            if (root->data.getAward().find(fieldKeyword) != string::npos) vecOfTreeNodes.push_back(root);
            _inOrderTraversal(field, fieldKeyword, root->left);
        }
        else if (field == ActorsActresses::NAME) {
            _inOrderTraversal(field, fieldKeyword, root->right);
            if (root->data.getName().find(fieldKeyword) != string::npos) vecOfTreeNodes.push_back(root);
            _inOrderTraversal(field, fieldKeyword, root->left);
        }
        else if (field == ActorsActresses::FILM) {
            _inOrderTraversal(field, fieldKeyword, root->right);
            if (root->data.getFilm().find(fieldKeyword) != string::npos) vecOfTreeNodes.push_back(root);
            _inOrderTraversal(field, fieldKeyword, root->left);
        }
    }
//    if (root != nullptr) {
//        if (field == ActorsActresses::AWARD) {
//            _inOrderTraversal(field, fieldKeyword, root->right, comparable);
//            if (comparable) vecOfTreeNodes.push_back(root);
//            _inOrderTraversal(field, fieldKeyword, root->left, comparable);
//        } else if (field == ActorsActresses::NAME) {
//            _inOrderTraversal(field, fieldKeyword, root->right, comparable);
//            if (comparable) vecOfTreeNodes.push_back(root);
//            _inOrderTraversal(field, fieldKeyword, root->left, comparable);
//        } else if (field == ActorsActresses::FILM) {
//            _inOrderTraversal(field, fieldKeyword, root->right, comparable);
//            if (comparable) vecOfTreeNodes.push_back(root);
//            _inOrderTraversal(field, fieldKeyword, root->left, comparable);
//        }
//    }

        // Print out the records which contain a specific keyword from a field.
    for (int i = 0; i < vecOfTreeNodes.size(); i++) {
        record++;
        cout << vecOfTreeNodes[i]->data << endl;
    }
    cout << record << endl;
}

///**
// * Partially search for records which contain a keyword in the award field.
// * @param field The specific field to partially search for.
// * @param awardKeyword The award keyword we want to find.
// */
//void ActorsActresses::partialFindByAward(string &field, string &awardKeyword) {
//
//    // Use the same instance from the tree with all the ActorsActresses database.
//    root = actorsTree->getRoot();
//
//    if (field == "award") {
//
//        // Traverse through each node in the BST and add any node which contains the keyword for the field.
//        _inOrderTraversalPS(field, awardKeyword, root);
//    }
//}
//
///**
// * Partially search for records which contain a keyword in the Name field.
// * @param field The specific field to partially search for.
// * @param nameKeyword The name keyword we want to find.
// */
//void ActorsActresses::partialFindByName(std::string &field, std::string &nameKeyword) {
//    root = actorsTree->getRoot();
//
//    if (field == "name") {
//        _inOrderTraversalPS(field, nameKeyword, root);
//    }
//}
//
///**
// * Partially search for records which contain a keyword in the Film field.
// * @param field The specific field to partially search for.
// * @param filmKeyword The film keyword we want to find.
// */
//void ActorsActresses::partialFindByFilm(std::string &field, std::string &filmKeyword) {
//    root = actorsTree->getRoot();
//
//    if (field == "film") {
//        _inOrderTraversalPS(field, filmKeyword, root);
//    }
//}
//
///**
// * Exactly search for records which contain a keyword in the Award field.
// * @param field The specific field to exactly search for.
// * @param awardKeyword The award keyword we want to find.
// */
//void ActorsActresses::exactFindByAward(std::string &field, std::string &awardKeyword) {
//    root = actorsTree->getRoot();
//
//    if (field == "award") {
//        _inOrderTraversalES(field, awardKeyword, root);
//    }
//}
//
///**
// * Exactly search for records which contain a keyword in the Name field.
// * @param field The specific field to exactly search for.
// * @param nameKeyword The name keyword we want to find.
// */
//void ActorsActresses::exactFindByName(std::string &field, std::string &nameKeyword) {
//
//    root = actorsTree->getRoot();
//
//    if (field == "name") {
//        _inOrderTraversalES(field, nameKeyword, root);
//    }
//}
//
///**
// * Exactly search for records which contain a keyword in the Award field.
// * @param field The specific field to exactly search for.
// * @param filmKeyword The film keyword we want to find.
// */
//void ActorsActresses::exactFindByFilm(std::string &field, std::string &filmKeyword) {
//    root = actorsTree->getRoot();
//
//    if (field == "film") {
//        _inOrderTraversalES(field, filmKeyword, root);
//    }
//}
//
///**
// * Traverse through the BST and add any records which contain a keyword we are looking for in a field (PS = Partial search).
// * @param field The specific field (award, name, film).
// * @param data The keyword.
// * @param root The root of the BST.
// */
//void ActorsActresses::_inOrderTraversalPS(string field, string data, BinaryTree<ActorsActresses>::TreeNode *root) {
//
//    vector<BinaryTree<ActorsActresses>::TreeNode*> vecOfTreeNodes;
//
//    if (field == "award") {
//        if (root != nullptr) {
//            _inOrderTraversalPS(field, data, root->left);
//            if (root->data.getAward().find(data) != std::string::npos) {
//                vecOfTreeNodes.push_back(root);  // Push any nodes which contain the keyword into the vector.
//            }
//            _inOrderTraversalPS(field, data, root->right);
//        }
//    }
//    else if (field == "name") {
//        if (root != nullptr) {
//            _inOrderTraversalPS(field, data, root->left);
//            if (root->data.getName().find(data) != std::string::npos) {
//                vecOfTreeNodes.push_back(root);
//            }
//            _inOrderTraversalPS(field, data, root->right);
//        }
//    }
//    else if (field == "film") {
//        if (root != nullptr) {
//            _inOrderTraversalPS(field, data, root->left);
//            if (root->data.getFilm().find(data) != std::string::npos) {
//                vecOfTreeNodes.push_back(root);
//            }
//            _inOrderTraversalPS(field, data, root->right);
//        }
//    }
//
//    // Print out the records which contain a specific keyword from a field.
//    for (int i = 0; i < vecOfTreeNodes.size(); i++) {
//        cout << vecOfTreeNodes[i]->data << endl;
//    }
//
//}
//
///**
// * Traverse through the BST and add any records which contain a keyword we are looking for in a field (ES = Exact search).
// * @param field The specific field (award, name, film).
// * @param data The keyword.
// * @param root The root of the BST.
// */
//void ActorsActresses::_inOrderTraversalES(string field, string data, BinaryTree<ActorsActresses>::TreeNode *root) {
//
//    // Create an empty vector of Binary Tree nodes of type ActorsActresses.
//    vector<BinaryTree<ActorsActresses>::TreeNode*> vecOfTreeNodes;
//
//    if (field == "award") {
//        if (root != nullptr) {
//            _inOrderTraversalES(field, data, root->left);
//            if (root->data.getAward() == data) {
//                vecOfTreeNodes.push_back(root);  // Push any nodes which contain the keyword into the vector.
//            }
//            _inOrderTraversalES(field, data, root->right);
//        }
//    }
//    else if (field == "name") {
//        if (root != nullptr) {
//            _inOrderTraversalES(field, data, root->left);
//            if (root->data.getName() == data) {
//                vecOfTreeNodes.push_back(root);
//            }
//            _inOrderTraversalES(field, data, root->right);
//        }
//    }
//    else if (field == "film") {
//        if (root != nullptr) {
//            _inOrderTraversalES(field, data, root->left);
//            if (root->data.getFilm() == data) {
//                vecOfTreeNodes.push_back(root);
//            }
//            _inOrderTraversalES(field, data, root->right);
//        }
//    }
//
//    // Print out the records which contain a specific keyword from a field.
//    for (int i = 0; i < vecOfTreeNodes.size(); i++) {
//        cout << vecOfTreeNodes[i]->data << endl;
//    }
//}







//
// Created by Bruce Tieu on 11/10/20.
//
#include <iostream>
#include <fstream>
#include <string>

//#include "ActorsBST.h"
#include "ActorsActresses.h"
//#include "BinaryTree.h"

using namespace std;

ActorsActresses::ActorsActresses() {

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
 * Create a new node.
 * @param actorsActresses The ActorsActresses object.
 * @return A the newNode.
 */
//BstNode* ActorsBST::getNewNode(ActorsActresses &actorsActresses) {
//    BstNode* newNode = new BstNode();
//
//    // Set the data.
//    newNode->actorsActresses->setYear(actorsActresses.getYear());
//    newNode->actorsActresses->setAward(actorsActresses.getAward());
//    newNode->actorsActresses->setWinner(actorsActresses.getWinner());
//    newNode->actorsActresses->setName(actorsActresses.getName());
//    newNode->actorsActresses->setFilm(actorsActresses.getFilm());
//
//    newNode->left = newNode->right = nullptr;
//
//    return newNode;
//}
//
//BstNode* ActorsBST::insert(BstNode *root, ActorsActresses actorsActresses) {
//    if(root == NULL) { // empty tree
//        root = getNewNode(actorsActresses);
//    }
//        // if data to be inserted is lesser, insert in left subtree.
//    else if(actorsActresses.getName() <= root->actorsActresses->getName()) {
//
//        root->left = insert(root->left, actorsActresses);
//    }
//        // else, insert in right subtree.
//    else {
//        root->right = insert(root->right, actorsActresses);
//    }
//    return root;
//}
//
///**
// * Read in "actor-actresses.csv".
// */
//BstNode* ActorsActresses::readInFile() {
//
//    string header;
////    ActorsActresses actorsActresses;
//
//    ActorsBST *actorsBst = new ActorsBST();
//    BstNode *root = new BstNode();
//
//    ifstream infile("actor-actress.csv");
//
//    int records = 0;
//
//    getline(infile, header);
//
//    while (infile.peek() != EOF) {
//
//        string year = getYear();
//        string name = getName();
//
//        getline(infile, year, ',');
//        getline(infile, award, ',');
//        getline(infile, winner, ',');
//        getline(infile, name, ',');
//        getline(infile, film, '\n');
//
//        root = actorsBst->insert(root, ActorsActresses(year, award, winner, name, film));
//        records++;
//    }
//    actorsBst->inorderTraversal(root);
//    return root;
//}



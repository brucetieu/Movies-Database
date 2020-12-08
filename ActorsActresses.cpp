//
// Created by Bruce Tieu on 11/10/20.
// Function implementations for ActorsActresses.cpp.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Utility.h"

#include "ActorsActresses.h"
#include "BinaryTree.h"

using namespace std;

// TODO: Probably should use an enum type.
string ActorsActresses::YEAR = "year";
string ActorsActresses::AWARD = "award";
string ActorsActresses::WINNER = "winner";
string ActorsActresses::NAME = "name";
string ActorsActresses::FILM = "film";


/**
 * Default constructor which initializes an Binary Tree of type ActorsActresses.
 */
ActorsActresses::ActorsActresses() {

    // Initialize a new BinaryTree holding ActorsActresses objects as nodes.
    actorsTree = new BinaryTree<ActorsActresses>();
    records = 0;
}

/**
 * Parameterized constructor to initialize member variables in Actors Actresses.
 * @param year The year of the film.
 * @param award The person who received the award (leading role, supporting role, etc).
 * @param winner If the film won (0 or 1).
 * @param name The name of the actor / actress.
 * @param film The name of the film.
 */
ActorsActresses::ActorsActresses(string &year, string &award, string &winner, string &name,
                                 string &film) {
    this->year = year;
    this->award = award;
    this->winner = winner;
    this->name = name;
    this->film = film;
}

// Setters - Encapsulation.
void ActorsActresses::setYear(string &year) { this->year = year; }
void ActorsActresses::setAward(string &award) { this->award = award; }
void ActorsActresses::setWinner(string &winner) { this->winner = winner; }
void ActorsActresses::setName(string &name) { this->name = name; }
void ActorsActresses::setFilm(string &film) { this->film = film; }

// Getters - Encapsulation.
string ActorsActresses::getYear() const { return year; }
string ActorsActresses::getAward() const {return award;}
string ActorsActresses::getWinner() const {return winner;}
string ActorsActresses::getName() const {return name; }
string ActorsActresses::getFilm() const {return film;}

int ActorsActresses::getRecords() const {return records;}

/**
 * Overload the '<' operator to compare objects by the Name field.
 * @param right The ActorsActresses object.
 * @return True, if the comparison is true for each record, false otherwise.
 */
bool ActorsActresses::operator<(const ActorsActresses &right) {
    return Utility::convertToLowerCase(name) < Utility::convertToLowerCase(right.getName());
}

/**
 * Overload the '>' operator to compare objects by Name field.
 * @param right The ActorsActresses Object passed in.
 * @return True, if the comparison is true, false otherwise.
 */
bool ActorsActresses::operator>(const ActorsActresses &right) {
    return Utility::convertToLowerCase(name) > Utility::convertToLowerCase(right.getName());
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
    return Utility::convertToLowerCase(name) >= Utility::convertToLowerCase(right.getName());
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
BinaryTree<ActorsActresses>::TreeNode* ActorsActresses::readInFile() {

    actorsTree->clearTree(root);
    string header;

    ifstream infile("actor-actress.csv");

    if (infile.fail()) {
        cerr << "Error reading file" << endl;
    }

    else {

        getline(infile, header);

        while (infile.peek() != EOF) {

            getline(infile, year, ',');
            getline(infile, award, ',');
            getline(infile, winner, ',');
            getline(infile, name, ',');
            getline(infile, film, '\n');

            // Insert each ActorsActresses object into the BST.
            root = actorsTree->insert(ActorsActresses(year, award, winner, name, film), root);
            records++;
        }
    }

    cout << "Success!" << endl;

    // Return pointer to TreeNode which is the root of the BST. We traverse through BST starting from root.
    return root;
}

/**
 * Add a record to the ActorsActresses database.
 * @param year The year of the film.
 * @param award The person who received the award (leading role, supporting role, etc).
 * @param winner If the film won (0 or 1).
 * @param name The name of the actor / actress.
 * @param film The name of the film.
 */
void ActorsActresses::addARecord(string &year, string &award, string &winner, string &name, string &film) {

    root = actorsTree->insert(ActorsActresses(year, award, winner, name, film), root);
    cout << "Record successfully inserted!" << endl;
    cout << actorsTree->getSize(root) << endl;
//    actorsTree->inorderPrint();
}

// TODO: Pass in a root here. Here, the root is still the root which was read into from the file.
/**
 * Find a record by a partially searched fields.
 * @param field The specific field.
 * @param fieldKeyword The keyword a user uses.
 * @param root Here, The root is the BST which contains all the results returned from the partial search.
 * @return A new root pointing to the node which contains all the results from the partial search.
 */
BinaryTree<ActorsActresses>::TreeNode* ActorsActresses::partialFindByField(std::string &field, std::string &fieldKeyword, BinaryTree<ActorsActresses>::TreeNode* root) {

    // We have the clear this vector because we are recursively adding new TreeNodes of partial matches to it.
    vecOfTreeNodes.clear();

    // Temporary vector of nodes to hold all the partial search records.
    vector<BinaryTree<ActorsActresses>::TreeNode*> tempRootVec;

    if (field == ActorsActresses::AWARD) {
        tempRootVec = _inOrderTraversalPS(field, fieldKeyword, root);
    } else if (field == ActorsActresses::NAME) {
        tempRootVec = _inOrderTraversalPS(field, fieldKeyword, root);
    } else if (field == ActorsActresses::FILM) {
        tempRootVec = _inOrderTraversalPS(field, fieldKeyword, root);
    }

    cout << "Number of partial searches returned: " << tempRootVec.size() << endl;

    if (tempRootVec.size() == 0) {
        cout << "No records found with that search keyword. Try again." << endl;

    }
    for (int i = 0; i < vecOfTreeNodes.size(); i++) {
        cout << vecOfTreeNodes[i]->data << endl;
    }

    return searchWithinASearch(tempRootVec); // Should contain all nodes from the partial search. The new root from the new BST.
}

/**
 * Recursively traverse through the BST and add nodes to vecOfTreeNodes if a node has a field which matches the keyword.
 * @param field The specific field.
 * @param fieldKeyword The keyword specified by the user.
 * @param root Here, the root points to the node with all the partially searched results.
 * @return The vector of TreeNode pointers which hold all of the records partially searched for based on field.
 */
vector<BinaryTree<ActorsActresses>::TreeNode*> ActorsActresses::_inOrderTraversalPS(std::string field, std::string fieldKeyword, BinaryTree<ActorsActresses>::TreeNode* root) {

    // Base case: If the root is null, just return an empty vector.
    if (root == nullptr) {
        return vecOfTreeNodes; // Contains all the nodes from the partial search.
    }

        // Recursive case: Root is not empty.
        // vecOfTreeNodes.push_back() works because it was cleared previously, so we get a vector of new nodes from each partial search.
    else if (root != nullptr) {
        string lowercaseFieldKey = Utility::convertToLowerCase(fieldKeyword);  // Convert the keyword to lowercase?
        if (field == ActorsActresses::AWARD) {

            string lowercaseAward = Utility::convertToLowerCase(root->data.getAward());  // Convert the current award field to be lowercase.

            _inOrderTraversalPS(field, fieldKeyword, root->right);
            if (lowercaseAward.find(lowercaseFieldKey) != string::npos) vecOfTreeNodes.push_back(root);
            _inOrderTraversalPS(field, fieldKeyword, root->left);
        }
        else if (field == ActorsActresses::NAME) {

            string lowercaseName = Utility::convertToLowerCase(root->data.getName());  // Convert name to lowercase.

            _inOrderTraversalPS(field, fieldKeyword, root->right);
            if (lowercaseName.find(lowercaseFieldKey) != string::npos) vecOfTreeNodes.push_back(root);
            _inOrderTraversalPS(field, fieldKeyword, root->left);
        }
        else if (field == ActorsActresses::FILM) {

            string lowercaseFilm = Utility::convertToLowerCase(root->data.getFilm());  // Convert film to lowercase.

            _inOrderTraversalPS(field, fieldKeyword, root->right);
            if (lowercaseFilm.find(lowercaseFieldKey) != string::npos) vecOfTreeNodes.push_back(root);
            _inOrderTraversalPS(field, fieldKeyword, root->left);
        }
    }

    return vecOfTreeNodes;
}

BinaryTree<ActorsActresses>::TreeNode* ActorsActresses::exactFindByField(std::string &field, std::string &fieldKeyword, BinaryTree<ActorsActresses>::TreeNode* root) {
    vecOfTreeNodes.clear();

    vector<BinaryTree<ActorsActresses>::TreeNode*> tempRootVec;

    if (field == ActorsActresses::YEAR) {
        tempRootVec = _inOrderTraversalES(field, fieldKeyword, root);
    } else if (field == ActorsActresses::AWARD) {
        tempRootVec = _inOrderTraversalES(field, fieldKeyword, root);
    } else if (field == ActorsActresses::WINNER){
        tempRootVec = _inOrderTraversalES(field, fieldKeyword, root);
    } else if (field == ActorsActresses::NAME) {
        tempRootVec = _inOrderTraversalES(field, fieldKeyword, root);
    } else if (field == ActorsActresses::FILM) {
        tempRootVec = _inOrderTraversalES(field, fieldKeyword, root);
    }

    cout << "Number of exact searches returned: " << tempRootVec.size() << endl;

    if (tempRootVec.size() == 0) {
        cout << "No records found with that search keyword. Try again." << endl;
    }
    else {
        for (int i = 0; i < vecOfTreeNodes.size(); i++) {
            cout << vecOfTreeNodes[i]->data << endl;
        }
    }

    return searchWithinASearch(tempRootVec);
}

vector<BinaryTree<ActorsActresses>::TreeNode*> ActorsActresses::_inOrderTraversalES(std::string field, std::string fieldKeyword,
                                                                                    BinaryTree<ActorsActresses>::TreeNode *root) {

    // Base case: If the root is null, just return an empty vector.
    if (root == nullptr) {
        return vecOfTreeNodes; // Contains all the nodes from the partial search.
    }

    else if (root != nullptr) {
        string lowercaseFieldKey = Utility::convertToLowerCase(fieldKeyword);
        if (field == ActorsActresses::YEAR) {

            string lowercaseYear = Utility::convertToLowerCase(root->data.getYear());

            _inOrderTraversalES(field, fieldKeyword, root->right);
            if (lowercaseYear == lowercaseFieldKey) vecOfTreeNodes.push_back(root);
            _inOrderTraversalES(field, fieldKeyword, root->left);
        }
        else if (field == ActorsActresses::AWARD) {

            string lowercaseAward = Utility::convertToLowerCase(root->data.getAward());

            _inOrderTraversalES(field, fieldKeyword, root->right);
            if (lowercaseAward == lowercaseFieldKey) vecOfTreeNodes.push_back(root);
            _inOrderTraversalES(field, fieldKeyword, root->left);
        }
        else if (field == ActorsActresses::NAME) {

            string lowercaseName = Utility::convertToLowerCase(root->data.getName());

            _inOrderTraversalES(field, fieldKeyword, root->right);
            if (lowercaseName == lowercaseFieldKey) vecOfTreeNodes.push_back(root);
            _inOrderTraversalES(field, fieldKeyword, root->left);
        }
        else if (field == ActorsActresses::WINNER) {

            string lowercaseWinner = Utility::convertToLowerCase(root->data.getWinner());

            _inOrderTraversalES(field, fieldKeyword, root->right);
            if (lowercaseWinner == lowercaseFieldKey) vecOfTreeNodes.push_back(root);
            _inOrderTraversalES(field, fieldKeyword, root->left);
        }
        else if (field == ActorsActresses::FILM) {

            string lowercaseFilm = Utility::convertToLowerCase(root->data.getFilm());

            _inOrderTraversalPS(field, fieldKeyword, root->right);
            if (lowercaseFilm == lowercaseFieldKey) vecOfTreeNodes.push_back(root);
            _inOrderTraversalPS(field, fieldKeyword, root->left);
        }
    }

    return vecOfTreeNodes;
}

/**
 * For each partial search, create a new binary tree out of it to update the root.
 * @param tempVec The vector of TreeNodes of partial searches.
 * @return A new root to hold nodes partially searched for.
 */
BinaryTree<ActorsActresses>::TreeNode* ActorsActresses::searchWithinASearch(vector<BinaryTree<ActorsActresses>::TreeNode*> tempVec) {

    BinaryTree<ActorsActresses>::TreeNode* newRoot = nullptr;

    // Create a new instance of BinaryTree object.
    BinaryTree<ActorsActresses> *tempTree = new BinaryTree<ActorsActresses>();

    // For each node in the vector, insert it into the new BST.
    for (int i = 0; i < tempVec.size(); i++) {
        newRoot = tempTree->insert(tempVec[i]->data, newRoot);
    }

    // Return the root of this new BST to recurse on.
    return newRoot;
}

/**
 * Traverse BST and add nodes to a vector.
 * @param root
 * @return
 */
vector<BinaryTree<ActorsActresses>::TreeNode*> ActorsActresses::traverseBST(
        BinaryTree<ActorsActresses>::TreeNode*& root, vector<BinaryTree<ActorsActresses>::TreeNode*> &vec) {

    if (root != nullptr){
        traverseBST(root->left, vec);
        vec.push_back(root);
        traverseBST(root->right, vec);
    }

    return vec;
}





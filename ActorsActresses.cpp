//
// Created by Bruce Tieu on 11/10/20.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "ActorsActresses.h"
#include "BinaryTree.h"

using namespace std;

// TODO: Probably should use an enum type.
string ActorsActresses::YEAR = "year";
string ActorsActresses::AWARD = "award";
string ActorsActresses::WINNER = "winner";
string ActorsActresses::NAME = "name";
string ActorsActresses::FILM = "film";



//bool ActorsActresses::sortByFieldComparator::operator(ActorsActresses &left, ActorsActresses &right) {
//    return left.getYear() < right.getYear();
//}



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

int ActorsActresses::getRecords() const {return records;}

std::vector<BinaryTree<ActorsActresses>::TreeNode *> ActorsActresses::getVecOfTreeNodesForSorting() {
    return vecOfTreeNodesForSorting;
}
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
BinaryTree<ActorsActresses>::TreeNode* ActorsActresses::readInFile() {

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
            actorsTree->insert(ActorsActresses(year, award, winner, name, film));
            records++;
        }
    }

    // Print out the contents in order by Name field.
//    actorsTree->inorderPrint();

    // TODO: Return a root when the file is read. Then, pass in that root as needed.
    // Return pointer to TreeNode which is the root of the BST. We traverse through BST starting from root.
    root = actorsTree->getRoot();

    cout << "Success!" << endl;

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

    actorsTree->insert(ActorsActresses(year, award, winner, name, film));
    cout << "Record successfully inserted!" << endl;
    actorsTree->inorderPrint();
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

    // Print out the records which contain a specific keyword from a field.
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

    // TODO: Using the vecOfTreeNodes, assemble a new BST with a new root.

    // Base case: If the root is null, just return an empty vector.
    if (root == nullptr) {
        return vecOfTreeNodes; // Contains all the nodes from the partial search.
    }

    // Recursive case: Root is not empty.
    // vecOfTreeNodes.push_back() works because it was cleared previously, so we get a vector of new nodes from each partial search.
    else if (root != nullptr) {
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

    for (int i = 0; i < vecOfTreeNodes.size(); i++) {
        cout << vecOfTreeNodes[i]->data << endl;
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

    return vecOfTreeNodes;
}

/**
 * For each partial search, create a new binary tree out of it to update the root.
 * @param tempVec The vector of TreeNodes of partial searches.
 * @return A new root to hold nodes partially searched for.
 */
BinaryTree<ActorsActresses>::TreeNode* ActorsActresses::searchWithinASearch(vector<BinaryTree<ActorsActresses>::TreeNode*> tempVec) {

    // Create a new instance of BinaryTree object.
    BinaryTree<ActorsActresses> *tempTree = new BinaryTree<ActorsActresses>();

    // For each node in the vector, insert it into the new BST.
    for (int i = 0; i < tempVec.size(); i++) {
        tempTree->insert(tempVec[i]->data);
    }

    // Return the root of this new BST to recurse on.
    return tempTree->getRoot();
}

/**
 * Traverse BST and add nodes to a vector.
 * @param root
 * @return
 */
vector<BinaryTree<ActorsActresses>::TreeNode*> ActorsActresses::traverseBST(
        BinaryTree<ActorsActresses>::TreeNode*& root, vector<BinaryTree<ActorsActresses>::TreeNode*> &vec) {

//    vecOfTreeNodesForSorting.clear();
//    vector<BinaryTree<ActorsActresses>::TreeNode*> vectorOfNodes;

//    if (root == nullptr) {
//        return vecOfTreeNodesForSorting;
//    }
//    else if (root != nullptr) {
//        traverseBST(root->left);

//        for (int i = 0; i < vecOfTreeNodesForSorting.size(); i++) {
//            if (vecOfTreeNodesForSorting[i]->data.getName() != root->data.getName() &&
//                vecOfTreeNodesForSorting[i]->data.getAward() != root->data.getAward() &&
//                vecOfTreeNodesForSorting[i]->data.getWinner() != root->data.getAward() &&
//                vecOfTreeNodesForSorting[i]->data.getYear() != root->data.getYear() &&
//                vecOfTreeNodesForSorting[i]->data.getFilm() != root->data.getFilm()) {
//                vecOfTreeNodesForSorting.push_back(root);
//            }
//        }
//        if (find(vecOfTreeNodesForSorting.begin(), vecOfTreeNodesForSorting.end(), root) == vecOfTreeNodesForSorting.end())
//            vecOfTreeNodesForSorting.push_back(root);
//        traverseBST(root->right);
//    }
     if (root != nullptr){
        traverseBST(root->left, vec);
         vec.push_back(root);
        traverseBST(root->right, vec);
    }
//     for (int i = 0; i < vectorOfNodes.size(); i++) {
//         cout << vectorOfNodes[i]->data << endl;
//     }
     return vec;

}






//
// Created by Bruce Tieu on 12/6/20.
// Function implementations for Pictures.h.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Utility.h"

#include "Pictures.h"
#include "BinaryTree.h"

using namespace std;

// Magic strings.
const string Pictures::NAME = "name";
const string Pictures::YEAR = "year";
const string Pictures::NOMINATIONS = "nominations";
const string Pictures::RATING = "rating";
const string Pictures::DURATION = "duration";
const string Pictures::GENRE1 = "genre1";
const string Pictures::GENRE2 = "genre2";
const string Pictures::RELEASE = "release";
const string Pictures::METACRITIC = "metacritic";
const string Pictures::SYNOPSIS = "synopsis";

/**
 * Default constructor which initializes an Binary Tree of type ActorsActresses.
 */
Pictures::Pictures() {

    // Initialize a new BinaryTree holding ActorsActresses objects as nodes.
    picturesTree = new BinaryTree<Pictures>();
    records = 0;
}

/**
 * Parameterized constructor to initialize field values.
 * @param name Name of movie.
 * @param year Year of movie.
 * @param nominations Number of nominations for the movie.
 * @param rating Rating of the movie.
 * @param duration Duration of the movie.
 * @param genre1 First genre of movie.
 * @param genre2 Second genre of movie.
 * @param release When the movie was released.
 * @param metacritic The metacritic score for the movie.
 * @param synopsis Quick premise of the movie.
 */
Pictures::Pictures(std::string &name, std::string &year, std::string &nominations, std::string &rating,
                   std::string &duration, std::string &genre1, std::string &genre2, std::string &release,
                   std::string &metacritic, std::string &synopsis) {
    this->name = name;
    this->year = year;
    this->nominations = nominations;
    this->rating = rating;
    this->duration = duration;
    this->genre1 = genre1;
    this->genre2 = genre2;
    this->release = release;
    this->metacritic = metacritic;
    this->synopsis = synopsis;
}

// Setters
void Pictures::setName(std::string &name) { this->name = name;}
void Pictures::setYear(std::string &year) { this->year = year;}
void Pictures::setNominations(std::string &nominations) { this->nominations = nominations; }
void Pictures::setRating(std::string &rating) { this->rating = rating; }
void Pictures::setDuration(std::string &duration) { this->duration = duration; }
void Pictures::setGenre1(std::string &genre1) { this->genre1 = genre1; }
void Pictures::setGenre2(std::string &genre2) { this->genre2 = genre2; }
void Pictures::setRelease(std::string &release) { this->release = release; }
void Pictures::setMetacritic(std::string &metacritic) { this->metacritic = metacritic; }
void Pictures::setSynopsis(std::string &synopsis) { this->synopsis = synopsis; }

// Getters
string Pictures::getName() const { return name; }
string Pictures::getYear() const { return year; }
string Pictures::getNominations() const { return nominations; }
string Pictures::getRating() const { return rating; }
string Pictures::getDuration() const { return duration; }
string Pictures::getGenre1() const { return genre1; }
string Pictures::getGenre2() const { return genre2; }
string Pictures::getRelease() const { return release; }
string Pictures::getMetacritic() const { return metacritic; }
string Pictures::getSynopsis() const { return synopsis; }

int Pictures::getRecords() const { return records; }


/**
 * Overload the '<' operator to compare objects by the Name field.
 * @param right The Pictures object.
 * @return True, if the comparison is true for each record, false otherwise.
 */
bool Pictures::operator<(const Pictures &right) {
    return Utility::convertToLowerCase(name) < Utility::convertToLowerCase(right.getName());
}

/**
 * Overload the '>' operator to compare objects by Name field.
 * @param right The Pictures Object passed in.
 * @return True, if the comparison is true, false otherwise.
 */
bool Pictures::operator>(const Pictures &right) {
    return Utility::convertToLowerCase(name) > Utility::convertToLowerCase(right.getName());
}

/**
 * Overload the '==' operator to see if objects are equal by the Name.
 * @param right The Pictures object being passed in.
 * @return True, if the comparison is true, false otherwise.
 */
bool Pictures::operator==(const Pictures &right) {
    return name == right.getName();
}

/**
 * Overload the '>=' operator to compare objects by Name.
 * @param right The Pictures object being passed in.
 * @return True, if the comparison is true.
 */
bool Pictures::operator>=(const Pictures &right) {
    return Utility::convertToLowerCase(name) >= Utility::convertToLowerCase(right.getName());
}

/**
 * Overload the '<<' operator to print out objects directly.
 * @param output The ostream object.
 * @param actor The Pictures object.
 * @return The output stream.
 */
ostream& operator << (ostream &output, const Pictures &pictures) {
    output << pictures.getName() << endl;
    output << pictures.getYear() << endl;
    output << pictures.getNominations() << endl;
    output << pictures.getRating() << endl;
    output << pictures.getDuration() << endl;
    output << pictures.getGenre1() << endl;
    output << pictures.getGenre2() << endl;
    output << pictures.getRelease() << endl;
    output << pictures.getMetacritic() << endl;
    output << pictures.getSynopsis() << endl;
    return output;
}

/**
 * Read in "pictures.csv" into a BST.
 */
BinaryTree<Pictures>::TreeNode* Pictures::readInFile() {

    // Clear the tree of any existing nodes.
    picturesTree->clearTree(root);
    string header;

    ifstream infile("pictures.csv");

    if (infile.fail()) {
        cerr << "Error reading file" << endl;
    }

    else {

        getline(infile, header);

        while (infile.peek() != EOF) {

            getline(infile, name, ',');
            getline(infile, year, ',');
            getline(infile, nominations, ',');
            getline(infile, rating, ',');
            getline(infile, duration, ',');
            getline(infile, genre1, ',');
            getline(infile, genre2, ',');
            getline(infile, release, ',');
            getline(infile, metacritic, ',');
            getline(infile, synopsis, '\n');

            // Insert each Pictures object into the BST.
            root = picturesTree->insert(Pictures(name, year, nominations, rating, duration, genre1, genre2, release, metacritic, synopsis), root);
            records++;
        }
    }

    // Return pointer to TreeNode which is the root of the BST. We traverse through BST starting from root.
    picturesTree->inorderPrint(root);

    cout << "Success!" << endl;

    return root;
}

/**
 * Add a record into the Pictures db.
 * @param name Name of movie.
 * @param year Year of movie.
 * @param nominations Number of nominations for the movie.
 * @param rating Rating of the movie.
 * @param duration Duration of the movie.
 * @param genre1 First genre of movie.
 * @param genre2 Second genre of movie.
 * @param release When the movie was released.
 * @param metacritic The metacritic score for the movie.
 * @param synopsis Quick premise of the movie.
 */
BinaryTree<Pictures>::TreeNode* Pictures::addARecord(std::string &name, std::string &year, std::string &nominations, std::string &rating,
                          std::string &duration, std::string &genre1, std::string &genre2, std::string &release,
                          std::string &metacritic, std::string &synopsis) {

    if (root == nullptr) {
        cout << "Must read in data first before adding a record" << endl;
        return root;
    }
//    else {
        // Update the new root when record is inserted.
        root = picturesTree->insert(
                Pictures(name, year, nominations, rating, duration, genre1, genre2, release, metacritic, synopsis),
                root);
        cout << "Record successfully inserted!" << endl;

        // Verify that we have an additional row in the db.
        cout << "Number of records in Pictures db: " << picturesTree->getSize(root) << endl;
        return root;
//    }
}

/**
 * Find a record by a partially searched fields in Pictures db.
 * @param field The specific field.
 * @param fieldKeyword The keyword a user uses.
 * @param root Here, The root is the BST which contains all the results returned from the partial search.
 * @return A new root pointing to the node which contains all the results from the partial search.
 */
BinaryTree<Pictures>::TreeNode* Pictures::partialFindByField(std::string &field, std::string &fieldKeyword,
                                  BinaryTree<Pictures>::TreeNode *root) {

    if (root == nullptr) {
        cout << "Must read in data first before searching a record" << endl;
        return root;
    }

    // We have the clear this vector because we are recursively adding new TreeNodes of partial matches to it.
    vecOfTreeNodes.clear();

    // Temporary vector of nodes to hold all the partial search records.
    vector<BinaryTree<Pictures>::TreeNode*> tempRootVec;

    if (field == Pictures::NAME) {
        tempRootVec = _inOrderTraversalPS(field, fieldKeyword, root);
    } else if (field == Pictures::YEAR) {
        tempRootVec = _inOrderTraversalPS(field, fieldKeyword, root);
    } else if (field == Pictures::NOMINATIONS) {
        tempRootVec = _inOrderTraversalPS(field, fieldKeyword, root);
    } else if (field == Pictures::RATING) {
        tempRootVec = _inOrderTraversalPS(field, fieldKeyword, root);
    } else if (field == Pictures::DURATION) {
        tempRootVec = _inOrderTraversalPS(field, fieldKeyword, root);
    } else if (field == Pictures::GENRE1) {
        tempRootVec = _inOrderTraversalPS(field, fieldKeyword, root);
    } else if (field == Pictures::GENRE2) {
        tempRootVec = _inOrderTraversalPS(field, fieldKeyword, root);
    } else if (field == Pictures::RELEASE) {
        tempRootVec = _inOrderTraversalPS(field, fieldKeyword, root);
    } else if (field == Pictures::METACRITIC) {
        tempRootVec = _inOrderTraversalPS(field, fieldKeyword, root);
    } else if (field == Pictures::SYNOPSIS) {
        tempRootVec = _inOrderTraversalPS(field, fieldKeyword, root);
    }

    if (tempRootVec.size() == 0) {
        cout << "No records found with that search keyword. Try again." << endl;
    }

    else {
        cout << "Number of partial searches returned: " << tempRootVec.size() << endl;
        for (int i = 0; i < vecOfTreeNodes.size(); i++) {
            cout << vecOfTreeNodes[i]->data << endl;
        }
    }

    return searchWithinASearch(tempRootVec); // Should contain all nodes from the secondary search. The new root from the new BST.
}

/**
 * Recursively traverse through the BST and add nodes to vecOfTreeNodes if a node has a field which matches the keyword.
 * @param field The specific field.
 * @param fieldKeyword The keyword specified by the user.
 * @param root Here, the root points to the node with all the partially searched results.
 * @return The vector of TreeNode pointers which hold all of the records partially searched for based on field.
 */
vector<BinaryTree<Pictures>::TreeNode*> Pictures::_inOrderTraversalPS(std::string field, std::string fieldKeyword, BinaryTree<Pictures>::TreeNode* root) {

    // Base case: If the root is null, just return an empty vector.
    if (root == nullptr) {
        return vecOfTreeNodes; // Contains all the nodes from the partial search.
    }

        // Recursive case: Root is not empty.
        // vecOfTreeNodes.push_back() works because it was cleared previously, so we get a vector of new nodes from each partial search.
    else if (root != nullptr) {
        string lowercaseFieldKey = Utility::convertToLowerCase(fieldKeyword);  // Convert the keyword to lowercase?
        if (field == Pictures::NAME) {

            string lowercaseAward = Utility::convertToLowerCase(root->data.getName());  // Convert the current award field to be lowercase.

            // Add any nodes to the vector with the specified keyword.
            _inOrderTraversalPS(field, fieldKeyword, root->right);
            if (lowercaseAward.find(lowercaseFieldKey) != string::npos) vecOfTreeNodes.push_back(root);
            _inOrderTraversalPS(field, fieldKeyword, root->left);
        }
        else if (field == Pictures::YEAR) {

            string lowercaseName = Utility::convertToLowerCase(root->data.getYear());  // Convert name to lowercase.

            _inOrderTraversalPS(field, fieldKeyword, root->right);
            if (lowercaseName.find(lowercaseFieldKey) != string::npos) vecOfTreeNodes.push_back(root);
            _inOrderTraversalPS(field, fieldKeyword, root->left);
        }
        else if (field == Pictures::NOMINATIONS) {

            string lowercaseFilm = Utility::convertToLowerCase(root->data.getNominations());  // Convert film to lowercase.

            _inOrderTraversalPS(field, fieldKeyword, root->right);
            if (lowercaseFilm.find(lowercaseFieldKey) != string::npos) vecOfTreeNodes.push_back(root);
            _inOrderTraversalPS(field, fieldKeyword, root->left);
        }
        else if (field == Pictures::RATING) {
            string lowercaseFilm = Utility::convertToLowerCase(root->data.getRating());  // Convert film to lowercase.

            _inOrderTraversalPS(field, fieldKeyword, root->right);
            if (lowercaseFilm.find(lowercaseFieldKey) != string::npos) vecOfTreeNodes.push_back(root);
            _inOrderTraversalPS(field, fieldKeyword, root->left);
        }
        else if (field == Pictures::DURATION) {
            string lowercaseFilm = Utility::convertToLowerCase(root->data.getDuration());  // Convert film to lowercase.

            _inOrderTraversalPS(field, fieldKeyword, root->right);
            if (lowercaseFilm.find(lowercaseFieldKey) != string::npos) vecOfTreeNodes.push_back(root);
            _inOrderTraversalPS(field, fieldKeyword, root->left);
        }
        else if (field == Pictures::GENRE1) {
            string lowercaseFilm = Utility::convertToLowerCase(root->data.getGenre1());  // Convert film to lowercase.

            _inOrderTraversalPS(field, fieldKeyword, root->right);
            if (lowercaseFilm.find(lowercaseFieldKey) != string::npos) vecOfTreeNodes.push_back(root);
            _inOrderTraversalPS(field, fieldKeyword, root->left);
        }
        else if (field == Pictures::GENRE2) {
            string lowercaseFilm = Utility::convertToLowerCase(root->data.getGenre2());  // Convert film to lowercase.

            _inOrderTraversalPS(field, fieldKeyword, root->right);
            if (lowercaseFilm.find(lowercaseFieldKey) != string::npos) vecOfTreeNodes.push_back(root);
            _inOrderTraversalPS(field, fieldKeyword, root->left);
        }
        else if (field == Pictures::RELEASE) {
            string lowercaseFilm = Utility::convertToLowerCase(root->data.getRelease());  // Convert film to lowercase.

            _inOrderTraversalPS(field, fieldKeyword, root->right);
            if (lowercaseFilm.find(lowercaseFieldKey) != string::npos) vecOfTreeNodes.push_back(root);
            _inOrderTraversalPS(field, fieldKeyword, root->left);
        }
        else if (field == Pictures::METACRITIC) {
            string lowercaseFilm = Utility::convertToLowerCase(root->data.getMetacritic());  // Convert film to lowercase.

            _inOrderTraversalPS(field, fieldKeyword, root->right);
            if (lowercaseFilm.find(lowercaseFieldKey) != string::npos) vecOfTreeNodes.push_back(root);
            _inOrderTraversalPS(field, fieldKeyword, root->left);
        }
        else if (field == Pictures::SYNOPSIS) {
            string lowercaseFilm = Utility::convertToLowerCase(root->data.getSynopsis());  // Convert film to lowercase.

            _inOrderTraversalPS(field, fieldKeyword, root->right);
            if (lowercaseFilm.find(lowercaseFieldKey) != string::npos) vecOfTreeNodes.push_back(root);
            _inOrderTraversalPS(field, fieldKeyword, root->left);
        }
    }

    return vecOfTreeNodes;
}

/**
 * Find a record by a exactly searching for any given field.
 * @param field The specific field.
 * @param fieldKeyword The keyword a user uses.
 * @param root Here, The root is the BST which contains all the results returned from the exact search.
 * @return A new root pointing to the node which contains all the results from the exact search.
 */
BinaryTree<Pictures>::TreeNode* Pictures::exactFindByField(std::string &field, std::string &fieldKeyword, BinaryTree<Pictures>::TreeNode* root) {

    // If BST hasn't been created yet, just return the null;
    if (root == nullptr) {
        cout << "Must read in data first before searching a record" << endl;
        return root;
    }

    vecOfTreeNodes.clear();

    // Contains all the nodes with exact searches.
    vector<BinaryTree<Pictures>::TreeNode*> tempRootVec;

    // Populate vector according to the different fields desired.
    if (field == Pictures::NAME) {
        tempRootVec = _inOrderTraversalES(field, fieldKeyword, root);
    } else if (field == Pictures::YEAR) {
        tempRootVec = _inOrderTraversalES(field, fieldKeyword, root);
    } else if (field == Pictures::NOMINATIONS){
        tempRootVec = _inOrderTraversalES(field, fieldKeyword, root);
    } else if (field == Pictures::RATING) {
        tempRootVec = _inOrderTraversalES(field, fieldKeyword, root);
    } else if (field == Pictures::DURATION) {
        tempRootVec = _inOrderTraversalES(field, fieldKeyword, root);
    } else if (field == Pictures::GENRE1) {
        tempRootVec = _inOrderTraversalES(field, fieldKeyword, root);
    } else if (field == Pictures::GENRE2) {
        tempRootVec = _inOrderTraversalES(field, fieldKeyword, root);
    } else if (field == Pictures::RELEASE) {
        tempRootVec = _inOrderTraversalES(field, fieldKeyword, root);
    } else if (field == Pictures::METACRITIC) {
        tempRootVec = _inOrderTraversalES(field, fieldKeyword, root);
    } else if (field == Pictures::SYNOPSIS) {
        tempRootVec = _inOrderTraversalES(field, fieldKeyword, root);
    }

    if (tempRootVec.size() == 0) {
        cout << "No records found with that search keyword. Try again." << endl;
    }
    else {
        cout << "Number of exact searches returned: " << tempRootVec.size() << endl;
        for (int i = 0; i < vecOfTreeNodes.size(); i++) {
            cout << vecOfTreeNodes[i]->data << endl;
        }
    }

    // Use this vector to perform a secondary search result if desired.
    return searchWithinASearch(tempRootVec);
}

/**
 * Traverse through the BST in order and add any nodes which match a keyword exactly.
 * @param field The specific field.
 * @param fieldKeyword The keyword specified by the user.
 * @param root The root of the BST.
 * @return The vector of all exact search nodes from Pictures.
 */
vector<BinaryTree<Pictures>::TreeNode*> Pictures::_inOrderTraversalES(std::string field, std::string fieldKeyword,
                                                                                    BinaryTree<Pictures>::TreeNode *root) {

    // Base case: If the root is null, just return an empty vector.
    if (root == nullptr) {
        return vecOfTreeNodes; // Contains all the nodes from the partial search.
    }

    // Recursive case: populate vectors with exact searches.
    else if (root != nullptr) {
        string lowercaseFieldKey = Utility::convertToLowerCase(fieldKeyword);
        if (field == Pictures::NAME) {

            string lowercaseYear = Utility::convertToLowerCase(root->data.getName());

            _inOrderTraversalES(field, fieldKeyword, root->right);
            if (lowercaseYear == lowercaseFieldKey) vecOfTreeNodes.push_back(root);
            _inOrderTraversalES(field, fieldKeyword, root->left);
        }
        else if (field == Pictures::YEAR) {

            string lowercaseAward = Utility::convertToLowerCase(root->data.getYear());

            _inOrderTraversalES(field, fieldKeyword, root->right);
            if (lowercaseAward == lowercaseFieldKey) vecOfTreeNodes.push_back(root);
            _inOrderTraversalES(field, fieldKeyword, root->left);
        }
        else if (field == Pictures::NOMINATIONS) {

            string lowercaseName = Utility::convertToLowerCase(root->data.getNominations());

            _inOrderTraversalES(field, fieldKeyword, root->right);
            if (lowercaseName == lowercaseFieldKey) vecOfTreeNodes.push_back(root);
            _inOrderTraversalES(field, fieldKeyword, root->left);
        }
        else if (field == Pictures::RATING) {

            string lowercaseWinner = Utility::convertToLowerCase(root->data.getRating());

            _inOrderTraversalES(field, fieldKeyword, root->right);
            if (lowercaseWinner == lowercaseFieldKey) vecOfTreeNodes.push_back(root);
            _inOrderTraversalES(field, fieldKeyword, root->left);
        }
        else if (field == Pictures::DURATION) {

            string lowercaseFilm = Utility::convertToLowerCase(root->data.getDuration());

            _inOrderTraversalPS(field, fieldKeyword, root->right);
            if (lowercaseFilm == lowercaseFieldKey) vecOfTreeNodes.push_back(root);
            _inOrderTraversalPS(field, fieldKeyword, root->left);
        }
        else if (field == Pictures::GENRE1) {
            string lowercaseFilm = Utility::convertToLowerCase(root->data.getGenre1());

            _inOrderTraversalPS(field, fieldKeyword, root->right);
            if (lowercaseFilm == lowercaseFieldKey) vecOfTreeNodes.push_back(root);
            _inOrderTraversalPS(field, fieldKeyword, root->left);
        }
        else if (field == Pictures::GENRE2) {
            string lowercaseFilm = Utility::convertToLowerCase(root->data.getGenre2());

            _inOrderTraversalPS(field, fieldKeyword, root->right);
            if (lowercaseFilm == lowercaseFieldKey) vecOfTreeNodes.push_back(root);
            _inOrderTraversalPS(field, fieldKeyword, root->left);
        }
        else if (field == Pictures::RELEASE) {
            string lowercaseFilm = Utility::convertToLowerCase(root->data.getRelease());

            _inOrderTraversalPS(field, fieldKeyword, root->right);
            if (lowercaseFilm == lowercaseFieldKey) vecOfTreeNodes.push_back(root);
            _inOrderTraversalPS(field, fieldKeyword, root->left);
        }
        else if (field == Pictures::METACRITIC) {
            string lowercaseFilm = Utility::convertToLowerCase(root->data.getMetacritic());

            _inOrderTraversalPS(field, fieldKeyword, root->right);
            if (lowercaseFilm == lowercaseFieldKey) vecOfTreeNodes.push_back(root);
            _inOrderTraversalPS(field, fieldKeyword, root->left);
        }
        else if (field == Pictures::SYNOPSIS) {
            string lowercaseFilm = Utility::convertToLowerCase(root->data.getSynopsis());

            _inOrderTraversalPS(field, fieldKeyword, root->right);
            if (lowercaseFilm == lowercaseFieldKey) vecOfTreeNodes.push_back(root);
            _inOrderTraversalPS(field, fieldKeyword, root->left);
        }
    }

    // Contains all the exact searches depending on the specific field.
    return vecOfTreeNodes;
}


/**
 * For each partial search, create a new binary tree out of it to update the root.
 * @param tempVec The vector of TreeNodes of partial searches.
 * @return A new root to hold nodes partially searched for.
 */
BinaryTree<Pictures>::TreeNode* Pictures::searchWithinASearch(vector<BinaryTree<Pictures>::TreeNode*> tempVec) {

    BinaryTree<Pictures>::TreeNode* newRoot = nullptr;

    // Create a new instance of BinaryTree object.
    BinaryTree<Pictures> *tempTree = new BinaryTree<Pictures>();

    // For each node in the vector, insert it into the new BST.
    for (int i = 0; i < tempVec.size(); i++) {
        newRoot = tempTree->insert(tempVec[i]->data, newRoot);
    }

    // Return the root of this new BST to recurse on.
    return newRoot;
}

/**
 * Traverse BST and add nodes to a vector.
 * @param root The root of the BST.
 * @return The BST in a vector.
 */
vector<BinaryTree<Pictures>::TreeNode*> Pictures::traverseBST(
        BinaryTree<Pictures>::TreeNode*& root, vector<BinaryTree<Pictures>::TreeNode*> &vec) {

    if (root != nullptr){
        traverseBST(root->left, vec);
        vec.push_back(root);
        traverseBST(root->right, vec);
    }

    return vec;
}
//
// Created by Bruce Tieu on 11/10/20.
// Function declarations for ActorsActresses database.
//

#ifndef MOVIES_DATABASE_ACTORSACTRESSES_H
#define MOVIES_DATABASE_ACTORSACTRESSES_H
#include <string>
#include "BinaryTree.h"
#include <fstream>
#include <vector>

/**
 * Define all members and methods for Actors Actresses database.
 */
class ActorsActresses {

private:
    std::string name;
    std::string year;
    std::string award;
    std::string winner;
    std::string film;

    int records;

    BinaryTree<ActorsActresses> *actorsTree;
    BinaryTree<ActorsActresses>::TreeNode* root;

    // Private helper methods for traversals.
    std::vector<BinaryTree<ActorsActresses>::TreeNode*> _inOrderTraversalPS(std::string field, std::string fieldKeyword, BinaryTree<ActorsActresses>::TreeNode* root);
    std::vector<BinaryTree<ActorsActresses>::TreeNode*> _inOrderTraversalES(std::string field, std::string fieldKeyword, BinaryTree<ActorsActresses>::TreeNode* root);

    std::vector<BinaryTree<ActorsActresses>::TreeNode*> vecOfTreeNodes;


public:

    static const std::string YEAR;
    static const std::string AWARD;
    static const std::string WINNER;
    static const std::string NAME;
    static const std::string FILM;

    /**
     * Functor object for sorting the ActorsActresses database by Year, Award, Winner, Name, and Film.
     */
    struct SortByFieldComparator {
        SortByFieldComparator(std::string &field) {this->field = field;}
        bool operator() (BinaryTree<ActorsActresses>::TreeNode* left, BinaryTree<ActorsActresses>::TreeNode* right) {
            if (field == ActorsActresses::YEAR) {
                return Utility::convertToLowerCase(left->data.getYear()) < Utility::convertToLowerCase(right->data.getYear());
            } else if (field == ActorsActresses::AWARD) {
                return Utility::convertToLowerCase(left->data.getAward()) < Utility::convertToLowerCase(right->data.getAward());
            } else if (field == ActorsActresses::WINNER) {
                return Utility::convertToLowerCase(left->data.getWinner()) < Utility::convertToLowerCase(right->data.getWinner());
            } else if (field == ActorsActresses::NAME) {
                return Utility::convertToLowerCase(left->data.getName()) < Utility::convertToLowerCase(right->data.getName());
            }
            return Utility::convertToLowerCase(left->data.getFilm()) < Utility::convertToLowerCase(right->data.getFilm());
        }
        std::string field;
    };


    ActorsActresses();
    ActorsActresses(std::string &year, std::string &award, std::string &winner, std::string &name, std::string &film);

    // Setters.
    void setYear(std::string &year);
    void setAward(std::string &award);
    void setWinner(std::string &winner);
    void setName(std::string &name);
    void setFilm(std::string &film);

    // Getters.
    std::string getYear() const;
    std::string getAward() const;
    std::string getWinner() const;
    std::string getName() const;
    std::string getFilm() const;
    int getRecords() const;

    // Methods for the database.
    BinaryTree<ActorsActresses>::TreeNode* readInFile();
    BinaryTree<ActorsActresses>::TreeNode* addARecord(std::string &year, std::string &award, std::string &winner, std::string &name, std::string &film);

    // Partial search on a field.
    BinaryTree<ActorsActresses>::TreeNode* partialFindByField(std::string &field, std::string &fieldKeyword, BinaryTree<ActorsActresses>::TreeNode* root);

    // Exact search on a field.
    BinaryTree<ActorsActresses>::TreeNode* exactFindByField(std::string &field, std::string &fieldKeyword, BinaryTree<ActorsActresses>::TreeNode* root);

    // Secondary search.
    BinaryTree<ActorsActresses>::TreeNode* searchWithinASearch(std::vector<BinaryTree<ActorsActresses>::TreeNode*> tempVec);

    // Inorder BST traversal.
    std::vector<BinaryTree<ActorsActresses>::TreeNode*> traverseBST(BinaryTree<ActorsActresses>::TreeNode*& root, std::vector<BinaryTree<ActorsActresses>::TreeNode*> &vec);

    // Overloaded operators.
    bool operator < (const ActorsActresses &right);
    bool operator > (const ActorsActresses &right);
    bool operator == (const ActorsActresses &right);
    bool operator >= (const ActorsActresses &right);

    // Overloaded output stream << operator.
    friend std::ostream &operator<<( std::ostream &output, const ActorsActresses &actor );

};

#endif //MOVIES_DATABASE_ACTORSACTRESSES_H

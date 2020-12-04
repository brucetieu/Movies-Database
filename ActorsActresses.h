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

    std::vector<BinaryTree<ActorsActresses>::TreeNode*> _inOrderTraversalPS(std::string field, std::string fieldKeyword, BinaryTree<ActorsActresses>::TreeNode* root);
    std::vector<BinaryTree<ActorsActresses>::TreeNode*> _inOrderTraversalES(std::string field, std::string fieldKeyword, BinaryTree<ActorsActresses>::TreeNode* root);

    std::vector<BinaryTree<ActorsActresses>::TreeNode*> vecOfTreeNodes;

    std::string _convertToLowerCase(const std::string &input);


public:

    static std::vector<BinaryTree<ActorsActresses>::TreeNode*> vecOfTreeNodesForSorting;

    static std::string YEAR;
    static std::string AWARD;
    static std::string WINNER;
    static std::string NAME;
    static std::string FILM;

    /**
     * Functor object for sorting the ActorsActresses database by Year, Award, Winner, Name, and Film.
     */
    struct SortByFieldComparator {
        SortByFieldComparator(std::string &field) {this->field = field;}
        bool operator() (BinaryTree<ActorsActresses>::TreeNode* left, BinaryTree<ActorsActresses>::TreeNode* right) {
            if (field == ActorsActresses::YEAR) {
                return left->data.getYear() < right->data.getYear();
            } else if (field == ActorsActresses::AWARD) {
                return left->data.getAward() < right->data.getAward();
            } else if (field == ActorsActresses::WINNER) {
                return left->data.getWinner() < right->data.getWinner();
            } else if (field == ActorsActresses::NAME) {
                return left->data.getName() < right->data.getName();
            }
            return left->data.getFilm() < right->data.getFilm();
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

    std::vector<BinaryTree<ActorsActresses>::TreeNode*> getVecOfTreeNodesForSorting();



    // Methods for the database.
    BinaryTree<ActorsActresses>::TreeNode* readInFile();
//    void readInFile();
    void addARecord(std::string &year, std::string &award, std::string &winner, std::string &name, std::string &film);

    // Partial search on a field.
    BinaryTree<ActorsActresses>::TreeNode* partialFindByField(std::string &field, std::string &fieldKeyword, BinaryTree<ActorsActresses>::TreeNode* root);
    BinaryTree<ActorsActresses>::TreeNode* exactFindByField(std::string &field, std::string &fieldKeyword, BinaryTree<ActorsActresses>::TreeNode* root);

    BinaryTree<ActorsActresses>::TreeNode* searchWithinASearch(std::vector<BinaryTree<ActorsActresses>::TreeNode*> tempVec);

//    void sortByField(std::string &field, BinaryTree<ActorsActresses>::TreeNode* root);

    std::vector<BinaryTree<ActorsActresses>::TreeNode*> traverseBST(BinaryTree<ActorsActresses>::TreeNode*& root, std::vector<BinaryTree<ActorsActresses>::TreeNode*> &vec);

//    bool operator()(ActorsActresses left, ActorsActresses right);
    static bool compareByFilm(ActorsActresses left, ActorsActresses right);

    // Overloaded operators.
    bool operator < (const ActorsActresses &right);
    bool operator > (const ActorsActresses &right);
    bool operator == (const ActorsActresses &right);
    bool operator >= (const ActorsActresses &right);

    // Overloaded output stream << operator.
    friend std::ostream &operator<<( std::ostream &output, const ActorsActresses &actor );

};

#endif //MOVIES_DATABASE_ACTORSACTRESSES_H

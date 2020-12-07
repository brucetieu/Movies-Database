//
// Created by Bruce Tieu on 12/6/20.
//

#ifndef MOVIES_DATABASE_PICTURES_H
#define MOVIES_DATABASE_PICTURES_H

#include <string>
#include "BinaryTree.h"
#include <fstream>
#include <vector>

class Pictures {
private:

    std::string name;
    std::string year;
    std::string nominations;
    std::string rating;
    std::string duration;
    std::string genre1;
    std::string genre2;
    std::string release;
    std::string metacritic;
    std::string synopsis;

    int records;

    BinaryTree<Pictures> *picturesTree;
    BinaryTree<Pictures>::TreeNode* root;

    std::vector<BinaryTree<Pictures>::TreeNode*> _inOrderTraversalPS(std::string field, std::string fieldKeyword, BinaryTree<Pictures>::TreeNode* root);
    std::vector<BinaryTree<Pictures>::TreeNode*> _inOrderTraversalES(std::string field, std::string fieldKeyword, BinaryTree<Pictures>::TreeNode* root);

    std::vector<BinaryTree<Pictures>::TreeNode*> vecOfTreeNodes;

public:
//    static std::vector<BinaryTree<Pictures>::TreeNode*> vecOfTreeNodesForSorting;

    static std::string NAME;
    static std::string YEAR;
    static std::string NOMINATIONS;
    static std::string RATING;
    static std::string DURATION;
    static std::string GENRE1;
    static std::string GENRE2;
    static std::string RELEASE;
    static std::string METACRITIC;
    static std::string SYNOPSIS;

    /**
     * Functor object for sorting the ActorsActresses database by Year, Award, Winner, Name, and Film.
     */
    struct SortByFieldComparator {
        SortByFieldComparator(std::string &field) {this->field = field;}
        bool operator() (BinaryTree<Pictures>::TreeNode* left, BinaryTree<Pictures>::TreeNode* right) {
            if (field == Pictures::NAME) {
                return Utility::convertToLowerCase(left->data.getName()) < Utility::convertToLowerCase(right->data.getName());
            } else if (field == Pictures::YEAR) {
                return Utility::convertToLowerCase(left->data.getYear()) < Utility::convertToLowerCase(right->data.getYear());
            } else if (field == Pictures::NOMINATIONS) {
                return Utility::convertToLowerCase(left->data.getNominations()) < Utility::convertToLowerCase(right->data.getNominations());
            } else if (field == Pictures::RATING) {
                return Utility::convertToLowerCase(left->data.getRating()) < Utility::convertToLowerCase(right->data.getRating());
            } else if (field == Pictures::DURATION) {
                return Utility::convertToLowerCase(left->data.getDuration()) < Utility::convertToLowerCase(right->data.getDuration());
            } else if (field == Pictures::GENRE1) {
                return Utility::convertToLowerCase(left->data.getGenre1()) < Utility::convertToLowerCase(right->data.getGenre1());
            } else if (field == Pictures::GENRE2) {
                return Utility::convertToLowerCase(left->data.getGenre2()) < Utility::convertToLowerCase(right->data.getGenre2());
            } else if (field == Pictures::RELEASE) {
                return Utility::convertToLowerCase(left->data.getRelease()) < Utility::convertToLowerCase(right->data.getRelease());
            } else if (field == Pictures::METACRITIC) {
                return Utility::convertToLowerCase(left->data.getMetacritic()) < Utility::convertToLowerCase(right->data.getMetacritic());
            }
            return Utility::convertToLowerCase(left->data.getSynopsis()) < Utility::convertToLowerCase(right->data.getSynopsis());
        }
        std::string field;
    };


    Pictures();
    Pictures(std::string &name, std::string &year, std::string &nominations, std::string &rating, std::string &duration, std::string &genre1,
             std::string &genre2, std::string &release, std::string &metacritic, std::string &synopsis);

    // Setters.
    void setName(std::string &name);
    void setYear(std::string &year);
    void setNominations(std::string &nominations);
    void setRating(std::string &rating);
    void setDuration(std::string &duration);
    void setGenre1(std::string &genre1);
    void setGenre2(std::string &genre2);
    void setRelease(std::string &release);
    void setMetacritic(std::string &metacritic);
    void setSynopsis(std::string &synopsis);

    // Getters.
    std::string getName() const;
    std::string getYear() const;
    std::string getNominations() const;
    std::string getRating() const;
    std::string getDuration() const;
    std::string getGenre1() const;
    std::string getGenre2() const;
    std::string getRelease() const;
    std::string getMetacritic() const;
    std::string getSynopsis() const;


    int getRecords() const;

//    std::vector<BinaryTree<Pictures>::TreeNode*> getVecOfTreeNodesForSorting();


    // Methods for the database.
    BinaryTree<Pictures>::TreeNode* readInFile();
    void addARecord(std::string &name, std::string &year, std::string &nominations, std::string &rating, std::string &duration, std::string &genre1,
                    std::string &genre2, std::string &release, std::string &metacritic, std::string &synopsis);

    // Partial search on a field.
    BinaryTree<Pictures>::TreeNode* partialFindByField(std::string &field, std::string &fieldKeyword, BinaryTree<Pictures>::TreeNode* root);
    BinaryTree<Pictures>::TreeNode* exactFindByField(std::string &field, std::string &fieldKeyword, BinaryTree<Pictures>::TreeNode* root);

    BinaryTree<Pictures>::TreeNode* searchWithinASearch(std::vector<BinaryTree<Pictures>::TreeNode*> tempVec);


    std::vector<BinaryTree<Pictures>::TreeNode*> traverseBST(BinaryTree<Pictures>::TreeNode*& root, std::vector<BinaryTree<Pictures>::TreeNode*> &vec);


    // Overloaded operators.
    bool operator < (const Pictures &right);
    bool operator > (const Pictures &right);
    bool operator == (const Pictures &right);
    bool operator >= (const Pictures &right);

    // Overloaded output stream << operator.
    friend std::ostream &operator<<( std::ostream &output, const Pictures &picture );
};


#endif //MOVIES_DATABASE_PICTURES_H

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

    // Keep track of number of records.
    int records;

    // Create a pictures Binary Tree.
    BinaryTree<Pictures> *picturesTree;

    // Root of BST.
    BinaryTree<Pictures>::TreeNode* root;

    // Traverse BST in order, to store partial matches.
    std::vector<BinaryTree<Pictures>::TreeNode*> _inOrderTraversalPS(std::string field, std::string fieldKeyword, BinaryTree<Pictures>::TreeNode* root);

    // Traverse BST in order, to store exact searches.
    std::vector<BinaryTree<Pictures>::TreeNode*> _inOrderTraversalES(std::string field, std::string fieldKeyword, BinaryTree<Pictures>::TreeNode* root);

    // Vector of TreeNode pointer objects.
    std::vector<BinaryTree<Pictures>::TreeNode*> vecOfTreeNodes;

public:

    const static std::string NAME;
    const static std::string YEAR;
    const static std::string NOMINATIONS;
    const static std::string RATING;
    const static std::string DURATION;
    const static std::string GENRE1;
    const static std::string GENRE2;
    const static std::string RELEASE;
    const static std::string METACRITIC;
    const static std::string SYNOPSIS;

    /**
     * Functor object for sorting the Pictures database by Name, Year, Nominations, Rating, Duration, Genre1, Genre2, Release, Metacritic, Synopsis.
     * @param field The specific field to be sorted.
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

    // Default constructor.
    Pictures();

    // Parameterized constructor to initialize all fields in Pictures.csv.
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

    // Read in data from file.
    BinaryTree<Pictures>::TreeNode* readInFile();

    // Add a record to the database.
    void addARecord(std::string &name, std::string &year, std::string &nominations, std::string &rating, std::string &duration, std::string &genre1,
                    std::string &genre2, std::string &release, std::string &metacritic, std::string &synopsis);

    // Partial search on a field.
    BinaryTree<Pictures>::TreeNode* partialFindByField(std::string &field, std::string &fieldKeyword, BinaryTree<Pictures>::TreeNode* root);

    // Exact search on a field.
    BinaryTree<Pictures>::TreeNode* exactFindByField(std::string &field, std::string &fieldKeyword, BinaryTree<Pictures>::TreeNode* root);

    // Search within a search (secondary search).
    BinaryTree<Pictures>::TreeNode* searchWithinASearch(std::vector<BinaryTree<Pictures>::TreeNode*> tempVec);

    // Traverse through BST and add nodes.
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

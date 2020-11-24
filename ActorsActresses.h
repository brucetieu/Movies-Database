//
// Created by Bruce Tieu on 11/10/20.
//

#ifndef MOVIES_DATABASE_ACTORSACTRESSES_H
#define MOVIES_DATABASE_ACTORSACTRESSES_H
#include <string>
#include "BinaryTree.h"
#include <fstream>
//#include "Database.h"
//#include "ActorsBST.h"

//class ActorsBST;
//class ActorsActresses;
//template <class T>
class ActorsActresses {

private:
    std::string name;
    std::string year;
    std::string award;
    std::string winner;
    std::string film;

    BinaryTree<ActorsActresses> *actorsTree;

    BinaryTree<ActorsActresses>::TreeNode* root;

    void _inOrderTraversalPS(std::string field, std::string data, BinaryTree<ActorsActresses>::TreeNode* root);
    void _inOrderTraversalES(std::string field, std::string data, BinaryTree<ActorsActresses>::TreeNode* root);

//    ActorsActresses *actorsActresses;

public:

    ActorsActresses();
    ActorsActresses(std::string year, std::string award, std::string winner, std::string name, std::string film);

    // Setters.
    void setYear(std::string year);
    void setAward(std::string award);
    void setWinner(std::string winner);
    void setName(std::string name);
    void setFilm(std::string film);

    // Getters.
    std::string getYear() const;
    std::string getAward() const;
    std::string getWinner() const;
    std::string getName() const;
    std::string getFilm() const;

    // Methods for the database.
    void readInFile();
    void addARecord(std::string year, std::string award, std::string winner, std::string name, std::string film);

    // Partial search on a field.
    void partialFindByAward(std::string &field, std::string &awardKeyword);
    void partialFindByName(std::string &field, std::string &nameKeyword);
    void partialFindByFilm(std::string &field, std::string &filmKeyword);

    // Exact search on a field.
    void exactFindByAward(std::string &field, std::string &awardKeyword);
    void exactFindByName(std::string &field, std::string &nameKeyword);
    void exactFindByFilm(std::string &field, std::string &filmKeyword);

    // Overloaded operators.
    bool operator < (const ActorsActresses &right);
    bool operator > (const ActorsActresses &right);
    bool operator == (const ActorsActresses &right);
    bool operator >= (const ActorsActresses &right);

    // Overloaded output stream << operator.
    friend std::ostream &operator<<( std::ostream &output, const ActorsActresses &actor );

};

//template <class T>
//ActorsActresses<T>::ActorsActresses() {
//
//}
//
//template <class T>
//ActorsActresses<T>::ActorsActresses(std::string year, std::string award, std::string winner, std::string name,
//                                 std::string film) {
//    this->year = year;
//    this->award = award;
//    this->winner = winner;
//    this->name = name;
//    this->film = film;
//}
//
//template <class T>
//void ActorsActresses<T>::setYear(std::string year) { this->year = year; }
//
//template <class T>
//void ActorsActresses<T>::setAward(std::string award) { this->award = award; }
//
//template <class T>
//void ActorsActresses<T>::setWinner(std::string winner) { this->winner = winner; }
//
//template <class T>
//void ActorsActresses<T>::setName(std::string name) { this->name = name; }
//
//template <class T>
//void ActorsActresses<T>::setFilm(std::string film) { this->film = film; }
//
//template <class T>
//std::string ActorsActresses<T>::getYear() const { return year; }
//
//template <class T>
//std::string ActorsActresses<T>::getAward() const {return award;}
//
//template <class T>
//std::string ActorsActresses<T>::getWinner() const {return winner;}
//
//template <class T>
//std::string ActorsActresses<T>::getName() const {return name; }
//
//template <class T>
//std::string ActorsActresses<T>::getFilm() const {return film;}
//
//template <class T>
//bool ActorsActresses<T>::operator<(const ActorsActresses<T> &right) {
//    return name < right.getName();
//}
//
//template <class T>
//bool ActorsActresses<T>::operator>(const ActorsActresses<T> &right) {
//    return name > right.getName();
//}
//
//template <class T>
//bool ActorsActresses<T>::operator==(const ActorsActresses<T> &right) {
//    return name == right.getName();
//}
//
//template <class T>
//bool ActorsActresses<T>::operator>=(const ActorsActresses<T> &right) {
//    return name >= right.getName();
//}
//
//template <class T>
//std::ostream& operator << (std::ostream &output, const ActorsActresses<T> &actor) {
//    output << actor.getYear() << std::endl;
//    output << actor.getAward() << std::endl;
//    output << actor.getWinner() << std::endl;
//    output << actor.getName() << std::endl;
//    output << actor.getFilm() << std::endl;
//    return output;
//}
//
//BinaryTree<ActorsActresses>::TreeNode* ActorsActresses::readInFile() {
//    BinaryTree<ActorsActresses> tree;
//
//    ifstream infile("actor-actress.csv");
//
//    int records = 0;
//
//    getline(infile, header);
//
//    while (infile.peek() != EOF) {
//
//        getline(infile, year, ',');
//        getline(infile, award, ',');
//        getline(infile, winner, ',');
//        getline(infile, name, ',');
//        getline(infile, film, '\n');
//
//        tree.insert(ActorsActresses<>)
//                records++;
//    }
//    actorsBst->inorderTraversal(root);
//    return root;
//}



#endif //MOVIES_DATABASE_ACTORSACTRESSES_H

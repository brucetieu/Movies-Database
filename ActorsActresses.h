//
// Created by Bruce Tieu on 11/10/20.
//

#ifndef MOVIES_DATABASE_ACTORSACTRESSES_H
#define MOVIES_DATABASE_ACTORSACTRESSES_H
#include "Database.h"


class ActorsActresses : public Database {

private:
//    std::string award;
//    std::string winner;
//    std::string film;

//    ActorsBST *actorsBst;
//    BstNode *root;

public:
    std::string award;
    std::string winner;
    std::string film;

    ActorsActresses();
    ActorsActresses(std::string name, std::string year, std::string award, std::string winner, std::string film);

//    void setAward(std::string award);
//    void setWinner(std::string winner);
//    void setFilm(std::string film);
//
//    std::string getAward();
//    std::string getWinner();
//    std::string getFilm();


    void readInFile();
};


#endif //MOVIES_DATABASE_ACTORSACTRESSES_H

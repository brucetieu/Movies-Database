//
// Created by Bruce Tieu on 11/10/20.
//

#ifndef MOVIES_DATABASE_ACTORSACTRESSES_H
#define MOVIES_DATABASE_ACTORSACTRESSES_H
#include <string>
//#include "BinaryTree.h"
//#include "Database.h"
//#include "ActorsBST.h"

//class ActorsBST;
//class ActorsActresses;

class ActorsActresses {

private:
    std::string name;
    std::string year;
    std::string award;
    std::string winner;
    std::string film;

public:
    ActorsActresses *left;
    ActorsActresses *right;

    ActorsActresses();
    ActorsActresses(std::string year, std::string award, std::string winner, std::string name, std::string film);

    void setYear(std::string year);
    void setAward(std::string award);
    void setWinner(std::string winner);
    void setName(std::string name);
    void setFilm(std::string film);

    std::string getYear() const;
    std::string getAward() const;
    std::string getWinner() const;
    std::string getName() const;
    std::string getFilm() const;

    // Overloaded operators
    bool operator < (const ActorsActresses &right);
    bool operator > (const ActorsActresses &right);
    bool operator == (const ActorsActresses &right);
    bool operator >= (const ActorsActresses &right);

    friend std::ostream &operator<<( std::ostream &output, const ActorsActresses &actor );


};



#endif //MOVIES_DATABASE_ACTORSACTRESSES_H

//
// Created by Bruce Tieu on 11/10/20.
//

#ifndef MOVIES_DATABASE_DATABASE_H
#define MOVIES_DATABASE_DATABASE_H
#include <string>
//#include "ActorsBST.h"



class Database {
private:
    std::string name;
    std::string year;
public:
//    std::string name, year, header;
    void setName(std::string name);
    void setYear(std::string year);

    std::string getName();
    std::string getYear();


    virtual void readInFile() = 0;
    virtual ~Database() {}
};


#endif //MOVIES_DATABASE_DATABASE_H

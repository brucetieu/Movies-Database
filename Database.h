//
// Created by Bruce Tieu on 11/10/20.
//

#ifndef MOVIES_DATABASE_DATABASE_H
#define MOVIES_DATABASE_DATABASE_H
#include <string>



class Database {
private:
//    std::string name, year;
public:
    std::string name, year, header;
    std::string getName();
    std::string getYear();

    virtual void readInFile() = 0;
};


#endif //MOVIES_DATABASE_DATABASE_H

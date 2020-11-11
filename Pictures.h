//
// Created by Bruce Tieu on 11/10/20.
//

#ifndef MOVIES_DATABASE_PICTURES_H
#define MOVIES_DATABASE_PICTURES_H
#include "Database.h"


class Pictures : public Database {
private:
    std::string rating;
    std::string nominations;
    std::string duration;
    std::string genre1;
    std::string genre2;
    std::string metacritic;
    std::string synopsis;
public:
    std::string getRating();
    std::string getNominations();
    std::string getDuration();
    std::string getGenre1();
    std::string getGenre2();
    std::string getMetacritic();
    std::string getSynopsis();

    void readInFile();
};

#endif //MOVIES_DATABASE_PICTURES_H

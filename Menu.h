//
// Created by Bruce Tieu on 11/21/20.
//

#ifndef MOVIES_DATABASE_MENU_H
#define MOVIES_DATABASE_MENU_H

#include "ActorsActresses.h"



class Menu {
private:

public:
//    enum class SearchCriteria {PARTIAL, EXACT};
    Menu();
    void mainMenu();
    void subMenuForA();
    void subMenuForB();
    void subMenuForC();

    void subMenuAddRecordInActors();
    void subMenuSearchRecordInActors();

    void searchActors();

    void partialSearchActorsField(std::string &field);
    void partialSearchActors();

    void exactSearchActorsField(std::string &field);
    void exactSearchActors();


private:
    ActorsActresses *actorsActresses;
};


#endif //MOVIES_DATABASE_MENU_H

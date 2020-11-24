//
// Created by Bruce Tieu on 11/21/20.
//

#ifndef MOVIES_DATABASE_MENU_H
#define MOVIES_DATABASE_MENU_H

#include "ActorsActresses.h"


class Menu {
public:
    Menu();
    void mainMenu();
    void subMenuForA();
    void subMenuForB();
    void subMenuForC();

    void subMenuAddRecordInActors();
    void subMenuSearchRecordInActors();

    void partialSearchActors();
    void exactSearchActors();

    void partialSearchAwardActors();
    void partialSearchNameActors();
    void partialSearchFilmActors();

    void exactSearchAwardActors();
    void exactSearchNameActors();
    void exactSearchFilmActors();

private:
    ActorsActresses *actorsActresses;
};


#endif //MOVIES_DATABASE_MENU_H

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
    void subMenuAddRecordInActors();

private:
    ActorsActresses *actorsActresses;
};


#endif //MOVIES_DATABASE_MENU_H

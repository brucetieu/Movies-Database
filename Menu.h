//
// Created by Bruce Tieu on 11/21/20.
//

#ifndef MOVIES_DATABASE_MENU_H
#define MOVIES_DATABASE_MENU_H

#include "ActorsActresses.h"

/**
 * Create menu driven system to navigate through the database.
 */
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

    void partialSearchActors();
    void exactSearchActors();

    BinaryTree<ActorsActresses>::TreeNode* partialSearchActorsField(std::string &field);
    BinaryTree<ActorsActresses>::TreeNode* exactSearchActorsField(std::string &field);

    void afterSearchActors();
    void searchAgainActors();

    void modifyARecordInActors();




private:
    ActorsActresses *actorsActresses;  // Declare pointer to ActorsActresses object.

    BinaryTree<ActorsActresses>::TreeNode* root; // Create the root for the BST.
};


#endif //MOVIES_DATABASE_MENU_H

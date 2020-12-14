//
// Created by Bruce Tieu on 11/21/20.
// Declarations for Menu functions.
//

#ifndef MOVIES_DATABASE_MENU_H
#define MOVIES_DATABASE_MENU_H

#include "ActorsActresses.h"
#include "Pictures.h"

/**
 * Create menu driven system to navigate through the database.
 */
class Menu {

private:
    ActorsActresses *actorsActresses;  // Declare pointer to ActorsActresses object.
    Pictures *pictures;  // Declare pointer to Pictures object.

    BinaryTree<ActorsActresses>::TreeNode* actorsRoot; // Create the root for Actors the BST.
    BinaryTree<Pictures>::TreeNode* picturesRoot; // Create the root for Pictures BST.

    static const std::string actorsFilename;
    static const std::string picturesFilename;

public:

    Menu();

    // Sub menu options in Actors db.
    void mainMenu();
    void subMenuForA();
    void subMenuForB();
    void subMenuForC();
    void subMenuForD();
    void subMenuForE();

    void subMenuAddRecordInActors();
    void subMenuSearchRecordInActors();
    void subMenuForSortingInActors();
    void partialSearchActors();
    void exactSearchActors();

    BinaryTree<ActorsActresses>::TreeNode* partialSearchActorsField(std::string field);
    BinaryTree<ActorsActresses>::TreeNode* exactSearchActorsField(std::string field);

    void afterSearchActors();

    void modifyARecordInActors();
    void sortByActorsFields(std::string field);
    void exportToCSVActors(BinaryTree<ActorsActresses>::TreeNode* root);

/***********************************************************/

    // Sub menu options in the Pictures db.
    void subMenuAddRecordInPictures();
    void subMenuSearchRecordInPictures();
    void subMenuForSortingInPictures();
    void partialSearchPictures();
    void exactSearchPictures();

    BinaryTree<Pictures>::TreeNode* partialSearchPicturesField(std::string field);
    BinaryTree<Pictures>::TreeNode* exactSearchPicturesField(std::string field);

    void afterSearchPictures();

    void modifyARecordInPictures();
    void sortByPicturesFields(std::string field);
    void exportToCSVPictures(BinaryTree<Pictures>::TreeNode* root);

};


#endif //MOVIES_DATABASE_MENU_H

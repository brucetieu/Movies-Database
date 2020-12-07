//
// Created by Bruce Tieu on 11/21/20.
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

public:
//    enum class SearchCriteria {PARTIAL, EXACT};
    Menu();
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

    BinaryTree<ActorsActresses>::TreeNode* partialSearchActorsField(std::string &field);
    BinaryTree<ActorsActresses>::TreeNode* exactSearchActorsField(std::string &field);

    void afterSearchActors();
//    void searchAgainActors();

    void modifyARecordInActors();
    void sortByActorsFields(std::string &field);
    void exportToCSVActors(BinaryTree<ActorsActresses>::TreeNode* root);

/***********************************************************/

    void subMenuAddRecordInPictures();
    void subMenuSearchRecordInPictures();
    void subMenuForSortingInPictures();
    void partialSearchPictures();
    void exactSearchPictures();

    BinaryTree<Pictures>::TreeNode* partialSearchPicturesField(std::string &field);
    BinaryTree<Pictures>::TreeNode* exactSearchPicturesField(std::string &field);

    void afterSearchPictures();
//    void searchAgainPictures();

    void modifyARecordInPictures();
    void sortByPicturesFields(std::string &field);
    void exportToCSVPictures(BinaryTree<Pictures>::TreeNode* root);



private:
    ActorsActresses *actorsActresses;  // Declare pointer to ActorsActresses object.
    Pictures *pictures;

    BinaryTree<ActorsActresses>::TreeNode* actorsRoot; // Create the root for the BST.
    BinaryTree<Pictures>::TreeNode* picturesRoot;

//    std::vector<BinaryTree<ActorsActresses>::TreeNode*> vectorOfNodes;
};


#endif //MOVIES_DATABASE_MENU_H

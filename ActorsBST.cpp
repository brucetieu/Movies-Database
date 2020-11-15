//
// Created by Bruce Tieu on 11/12/20.
//

#include "ActorsBST.h"

/**
 * Create a new node.
 * @param actorsActresses The ActorsActresses object.
 * @return A the newNode.
 */
BstNode* ActorsBST::getNewNode(ActorsActresses &actorsActresses) {
    BstNode* newNode = new BstNode();

    newNode->actorsActresses.name = actorsActresses.name;
    newNode->actorsActresses.year = actorsActresses.year;
    newNode->actorsActresses.setAward(actorsActresses.getAward());
    newNode->actorsActresses.setWinner(actorsActresses.getWinner());
    newNode->actorsActresses.setFilm(actorsActresses.getFilm());

    newNode->left = newNode->right = NULL;

    return newNode;
}

BstNode* ActorsBST::insert(BstNode *root, ActorsActresses &actorsActresses) {
    if(root == NULL) { // empty tree
        root = getNewNode(actorsActresses);
    }
    // if data to be inserted is lesser, insert in left subtree.
    else if(actorsActresses.name <= root->actorsActresses.name ||
            actorsActresses.year <= root->actorsActresses.year ||
            actorsActresses.getAward() <= root->actorsActresses.getAward() ||
            actorsActresses.getWinner() <= root->actorsActresses.getWinner() ||
            actorsActresses.getFilm() <= root->actorsActresses.getFilm()) {

        root->left = insert(root->left, actorsActresses);
    }
        // else, insert in right subtree.
    else {
        root->right = insert(root->right, actorsActresses);
    }
    return root;
}



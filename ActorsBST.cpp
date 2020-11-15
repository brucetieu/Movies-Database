//
// Created by Bruce Tieu on 11/12/20.
//

#include "ActorsBST.h"

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

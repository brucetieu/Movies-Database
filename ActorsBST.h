//
// Created by Bruce Tieu on 11/12/20.
//

#ifndef MOVIES_DATABASE_ACTORSBST_H
#define MOVIES_DATABASE_ACTORSBST_H
#include "ActorsActresses.h"

struct BstNode {
    ActorsActresses actorsActresses;
    BstNode *left;
    BstNode *right;
};

class ActorsBST {
private:
public:
    BstNode* getNewNode(ActorsActresses &actorsActresses);
    BstNode* insert(BstNode *root, ActorsActresses &actorsActresses);

};


#endif //MOVIES_DATABASE_ACTORSBST_H

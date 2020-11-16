//
// Created by Bruce Tieu on 11/12/20.
//

#ifndef MOVIES_DATABASE_ACTORSBST_H
#define MOVIES_DATABASE_ACTORSBST_H
#include "ActorsActresses.h"


class ActorsBST {
private:
//    struct BstNode {
//        ActorsActresses* actorsActresses;
//        BstNode *left;
//        BstNode *right;
//    };

public:

    struct BstNode {
        ActorsActresses actorsActresses;
        BstNode *left;
        BstNode *right;
    };

    BstNode* getNewNode(ActorsActresses &actorsActresses);
    BstNode* insert(BstNode *root, ActorsActresses &actorsActresses);
    void inorderTraversal(BstNode *root);

};


#endif //MOVIES_DATABASE_ACTORSBST_H

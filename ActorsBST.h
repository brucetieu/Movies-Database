//
// Created by Bruce Tieu on 11/12/20.
//

#ifndef MOVIES_DATABASE_ACTORSBST_H
#define MOVIES_DATABASE_ACTORSBST_H

#include "ActorsActresses.h"
//class ActorsActresses;

//struct BstNode {
//    ActorsActresses *actorsActresses;
//    BstNode *left;
//    BstNode *right;
//};

template<class T>
class ActorsBST {

private:
    ActorsActresses *root;
public:
    ActorsBST() {
        root = nullptr;
    }

    T* getNewNode(T data) {
        ActorsActresses *newNode = new ActorsActresses();
        newNode->setYear(data.getYear());
        newNode->setAward(data.getAward());
        newNode->setWinner(data.getWinner());
        newNode->setName(data.getName());
        newNode->setFilm(data.getFilm());

        newNode->left = newNode->right = nullptr;

        return newNode;
    }

    T* insert(T *root, T data) {
        if (root == NULL) { // empty tree
            root = getNewNode(data);
        }
            // if data to be inserted is lesser, insert in left subtree.
        else if (data.getName() <= root->getName()) {

            root->left = insert(root->left, data);
        }
            // else, insert in right subtree.
        else {
            root->right = insert(root->right, data);
        }
        return root;
    }

//    BstNode* getNewNode(ActorsActresses &actorsActresses);
//    BstNode* insert(BstNode *root, ActorsActresses actorsActresses);
//    void inorderTraversal(BstNode *root);
//    bool search(BstNode* root, ActorsActresses &actorsActresses);

};


#endif //MOVIES_DATABASE_ACTORSBST_H

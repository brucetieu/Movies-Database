//
// Created by Bruce Tieu on 11/12/20.
//

#include "ActorsBST.h"
#include <iostream>


/**
 * Create a new node.
 * @param actorsActresses The ActorsActresses object.
 * @return A the newNode.
 */
ActorsBST::BstNode* ActorsBST::getNewNode(ActorsActresses &actorsActresses) {
    BstNode* newNode = new BstNode();

    newNode->actorsActresses.name = actorsActresses.name;
    newNode->actorsActresses.year = actorsActresses.year;
    newNode->actorsActresses.award = actorsActresses.award;
    newNode->actorsActresses.winner = actorsActresses.winner;
    newNode->actorsActresses.film =  actorsActresses.film;

    newNode->left = newNode->right = nullptr;

    return newNode;
}

ActorsBST::BstNode* ActorsBST::insert(BstNode *root, ActorsActresses &actorsActresses) {
    if(root == NULL) { // empty tree
        root = getNewNode(actorsActresses);
    }
    // if data to be inserted is lesser, insert in left subtree.
    else if(actorsActresses.name <= root->actorsActresses.name ||
            actorsActresses.year <= root->actorsActresses.year ||
            actorsActresses.award <= root->actorsActresses.award ||
            actorsActresses.winner <= root->actorsActresses.winner ||
            actorsActresses.film <= root->actorsActresses.film) {

        root->left = insert(root->left, actorsActresses);
    }
        // else, insert in right subtree.
    else {
        root->right = insert(root->right, actorsActresses);
    }
    return root;
}

/**
 * Inorder traversal: left -> visit -> right
 * @param root The root
 */
void ActorsBST::inorderTraversal(BstNode *root) {
    if (root == nullptr) {
        return;
    } else {
        inorderTraversal(root->left);
        std::cout << root->actorsActresses.year << std::endl;
        std::cout << root->actorsActresses.award << std::endl;
        std::cout << root->actorsActresses.name << std::endl;
        std::cout << root->actorsActresses.winner << std::endl;
        std::cout << root->actorsActresses.film << std::endl;
        std::cout << std::endl;
        inorderTraversal(root->right);
    }
}



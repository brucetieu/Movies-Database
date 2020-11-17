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
ActorsBST::BstNode* ActorsBST::getNewNode(ActorsActresses actorsActresses) {
    BstNode* newNode = new BstNode();

    newNode->actorsActresses.setYear(actorsActresses.getYear());
    newNode->actorsActresses.setAward(actorsActresses.getAward());
    newNode->actorsActresses.setWinner(actorsActresses.getWinner());
    newNode->actorsActresses.setName(actorsActresses.getName());
    newNode->actorsActresses.setFilm(actorsActresses.getFilm());

    newNode->left = newNode->right = nullptr;

    return newNode;
}

ActorsBST::BstNode* ActorsBST::insert(BstNode *root, ActorsActresses actorsActresses) {
    if(root == NULL) { // empty tree
        root = getNewNode(actorsActresses);
    }
    // if data to be inserted is lesser, insert in left subtree.
    else if(actorsActresses.getName() <= root->actorsActresses.getName()) {

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
        std::cout << root->actorsActresses.getYear() << std::endl;
        std::cout << root->actorsActresses.getAward() << std::endl;
        std::cout << root->actorsActresses.getName() << std::endl;
        std::cout << root->actorsActresses.getWinner() << std::endl;
        std::cout << root->actorsActresses.getFilm() << std::endl;
        std::cout << std::endl;
        inorderTraversal(root->right);
    }
}



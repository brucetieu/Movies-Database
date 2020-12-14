//
// Created by Bruce Tieu on 11/18/20.
//

#ifndef MOVIES_DATABASE_BINARYTREE_H
#define MOVIES_DATABASE_BINARYTREE_H

#include <iostream>
#include "Utility.h"

/**
 * Construct a binary tree.
 * @tparam T BST can be of any type.
 */
template<class T>
class BinaryTree {

public:

    /**
     * This represents a node in the BST.
     */
    struct TreeNode {
        T data;
        TreeNode *left;
        TreeNode *right;
    };

    BinaryTree();
    void inorderPrint(BinaryTree<T>::TreeNode* root);
    TreeNode* getRoot();

    int getSize(TreeNode* root);

    TreeNode* getNewNode(T data);
    TreeNode* insert(T data, BinaryTree<T>::TreeNode *root);

    void clearTree(TreeNode*& root);

private:
    TreeNode *root;
    int size;
};

/**
 * Initialize root to null and size of BST to 0.
 * @tparam T The class type.
 */
template <class T>
BinaryTree<T>::BinaryTree() {
    root = nullptr;
    size = 0;
}

/**
 * Get the root of the BST.
 * @tparam T The class type.
 * @return The root of the BST
 */
template <class T>
typename BinaryTree<T>::TreeNode* BinaryTree<T>::getRoot() {
    return root;
}

/**
 * Print out the BST in sorted order.
 * @tparam T The class type.
 * @return The root of the BST
 */
template <class T>
void BinaryTree<T>::inorderPrint(BinaryTree<T>::TreeNode *root) {
    if (root == nullptr) {
        return;
    } else {
        inorderPrint(root->left);
        std::cout << root->data << std::endl;
        inorderPrint(root->right);
    }
}

/**
 * Create a new node.
 * @tparam T The class type
 * @param data A data of type T.
 * @return The new node.
 */
template <class T>
typename BinaryTree<T>::TreeNode* BinaryTree<T>::getNewNode(T data) {
    BinaryTree<T>::TreeNode* newNode = new BinaryTree<T>::TreeNode();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

/**
 * Insert a node into the BST.
 * @tparam T The class type.
 * @param data The data.
 * @param root The root of the BST.
 * @return The updated root after inserting.
 */
template <class T>
typename BinaryTree<T>::TreeNode* BinaryTree<T>::insert(T data, BinaryTree<T>::TreeNode *root) {
    if(root == NULL) { // empty tree
        root = getNewNode(data);
    }
        // if data to be inserted is lesser, insert in left subtree.
    else if(data < root->data) {

        root->left = insert(data, root->left);
    }
        // else, insert in right subtree.
    else {

        root->right = insert(data, root->right);
    }

    return root;
}

/**
 * Clear all nodes in the BST.
 * @tparam T The class type.
 * @param root The root of the BST.
 */
template <class T>
void BinaryTree<T>::clearTree(TreeNode *&root) {
    if (root == nullptr){
        return;
    }
    clearTree(root->left);
    clearTree(root->right);

    delete root;
    root = nullptr;
}

/**
 * Get the size of the BST.
 * @tparam T The class type.
 * @param root The root of the BST.
 * @return The size.
 */
template <class T>
int BinaryTree<T>::getSize(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + getSize(root->left) + getSize(root->right);
}


#endif //MOVIES_DATABASE_BINARYTREE_H

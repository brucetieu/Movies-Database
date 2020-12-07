//
// Created by Bruce Tieu on 11/18/20.
//

#ifndef MOVIES_DATABASE_BINARYTREE_H
#define MOVIES_DATABASE_BINARYTREE_H

#include <iostream>
#include "Utility.h"


template<class T>
class BinaryTree {

public:

    struct TreeNode {
        T data;
        TreeNode *left;
        TreeNode *right;
    };

    BinaryTree();
//    void insert(T data);
    void inorderPrint(BinaryTree<T>::TreeNode* root);
//    std::vector<TreeNode*> search(T data);
//    bool search(T data);
    TreeNode* getRoot();

    int getSize(TreeNode* root);

    TreeNode* getNewNode(T data);
    TreeNode* insert(T data, BinaryTree<T>::TreeNode *root);

    void clearTree(TreeNode*& root);


private:
    TreeNode *root;
    int size;

//    void _insert(T data, TreeNode* leaf);
//    void _inorderPrint(TreeNode* leaf);
//    bool _search(T data, TreeNode* leaf);
//    std::vector<TreeNode*> _search(T data, TreeNode* leaf);

};

template <class T>
BinaryTree<T>::BinaryTree() {
    root = nullptr;
    size = 0;
}

template <class T>
typename BinaryTree<T>::TreeNode* BinaryTree<T>::getRoot() {
    return root;
}

/**
 * Helper function which Recursively inserts new nodes by comparing the data of each node.
 * @tparam T Type T.
 * @param data The data / value.
 * @param leaf The leaf node.
 */
//template <class T>
//void BinaryTree<T>::_insert(T data, TreeNode *leaf) {
//
//    if (data < leaf->data){
//
//        // Traversing the BST until we can insert a leaf node in the proper location.
//        if (leaf->left != nullptr){
//            _insert(data, leaf->left);
//        }
//
//            // Inserting a leaf node. The base case.
//        else {
//            leaf->left = new TreeNode;
//            leaf->left->data = data;
//            leaf->left->left = NULL;
//            leaf->left->right = NULL;
//        }
//    } else if (data >= leaf->data) {
//        if (leaf->right != nullptr) {
//            _insert(data, leaf->right);
//        } else{
//            leaf->right = new TreeNode;
//            leaf->right->data = data;
//            leaf->right->right = NULL;
//            leaf->right->left = NULL;
//        }
//    }
//}

/**
 * Building the BST - we are keeping track of the root node and insert nodes from there.
 * @tparam T
 * @param data
 */
//template <class T>
//void BinaryTree<T>::insert(T data) {
//
//    // Insert successful nodes after the first node (the root node) is inserted.
//    if (root != nullptr) {
//        _insert(data, root);
//    }
//
//        // If root is null, create a new tree node. This inserts the first node.
//    else {
//        root = new TreeNode;
//        root->data = data;
//        root->left = nullptr;
//        root->right = nullptr;
//    }
//}

/**
 * Inorder traversal: left -> visit -> right
 * @param root The root
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
 * Print the BS tree in-order: left - visit - right.
 * @tparam T The Type.
 */
//template <class T>
//void BinaryTree<T>::inorderPrint() {
//    _inorderPrint(root);
//    std::cout << "\n";
//}

/**
 * Helper method which recursively traverses through the BST to insert nodes in-order.
 * @tparam T The type.
 * @param leaf The leaf node.
 */
//template <class T>
//void BinaryTree<T>::_inorderPrint(TreeNode* leaf) {
//
//    if (leaf != nullptr) {
//        _inorderPrint(leaf->left);
//        std::cout << leaf->data << std::endl;
//        _inorderPrint(leaf->right);
//    }
//}

template <class T>
typename BinaryTree<T>::TreeNode* BinaryTree<T>::getNewNode(T data) {
    BinaryTree<T>::TreeNode* newNode = new BinaryTree<T>::TreeNode();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

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

template <class T>
int BinaryTree<T>::getSize(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + getSize(root->left) + getSize(root->right);
}


#endif //MOVIES_DATABASE_BINARYTREE_H

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
    void insert(T data);
    void inorderPrint();
//    std::vector<TreeNode*> search(T data);
    bool search(T data);
    TreeNode* getRoot();


private:
    TreeNode *root;

    void _insert(T data, TreeNode* leaf);
    void _inorderPrint(TreeNode* leaf);
    bool _search(T data, TreeNode* leaf);
//    std::vector<TreeNode*> _search(T data, TreeNode* leaf);

};

template <class T>
BinaryTree<T>::BinaryTree() {
    root = nullptr;
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
template <class T>
void BinaryTree<T>::_insert(T data, TreeNode *leaf) {

    if (data < leaf->data){

        // Traversing the BST until we can insert a leaf node in the proper location.
        if (leaf->left != nullptr){
            _insert(data, leaf->left);
        }

        // Inserting a leaf node. The base case.
        else {
            leaf->left = new TreeNode;
            leaf->left->data = data;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    } else if (data >= leaf->data) {
        if (leaf->right != nullptr) {
            _insert(data, leaf->right);
        } else{
            leaf->right = new TreeNode;
            leaf->right->data = data;
            leaf->right->right = NULL;
            leaf->right->left = NULL;
        }
    }
}

/**
 * Building the BST - we are keeping track of the root node and insert nodes from there.
 * @tparam T
 * @param data
 */
template <class T>
void BinaryTree<T>::insert(T data) {

    // Insert successful nodes after the first node (the root node) is inserted.
    if (root != nullptr) {
        _insert(data, root);
    }

    // If root is null, create a new tree node. This inserts the first node.
    else {
        root = new TreeNode;
        root->data = data;
        root->left = nullptr;
        root->right = nullptr;
    }
}

/**
 * Print the BS tree in-order: left - visit - right.
 * @tparam T The Type.
 */
template <class T>
void BinaryTree<T>::inorderPrint() {
    _inorderPrint(root);
    std::cout << "\n";
}

/**
 * Helper method which recursively traverses through the BST to insert nodes in-order.
 * @tparam T The type.
 * @param leaf The leaf node.
 */
template <class T>
void BinaryTree<T>::_inorderPrint(TreeNode* leaf) {

    if (leaf != nullptr) {
        _inorderPrint(leaf->left);
        std::cout << leaf->data << std::endl;
        _inorderPrint(leaf->right);
    }
}

template <class T>
bool BinaryTree<T>::_search(T data, TreeNode* leaf) {
    // Create temporary node to keep track of the root.
//    TreeNode* tempNode = root;
//
//    // Create a vector of treenodes.
//    std::vector<BinaryTree<T>::TreeNode*> vecOfNodes;
//
//    // Traverse the BST. If a value in the bst corresponds to a keyword, then add it to the vector.
//    while (tempNode != nullptr) {
//        if (tempNode->data.find(data) != std::string::npos) {
//            vecOfNodes.push_back(*tempNode);
//        } else if (data < tempNode->data) {
//            tempNode = tempNode->left;
//        } else
//            tempNode = tempNode->right;
//    }
//    return vecOfNodes;
    if (leaf != nullptr) {
        std::cout << "Not null" << std::endl;
        if (data == leaf->data) {
            std::cout << "Found" << std::endl;
            return true;
        } else if (data < leaf->data) {
//            std::cout << leaf->data << std::endl;
            return _search(data, leaf->left);
        } else if (data >= leaf->data) {
//            std::cout << leaf->data << std::endl;
            return _search(data, leaf->right);
        }
    }
//    std::cout << "Not found" << std::endl;
    return false;
//       return false;
//    TreeNode *nodePtr = root;

//    while (nodePtr) {
//        if (nodePtr->data == data) {
//            cout << nodePtr->data << endl;
//            return true;
//        }
//        else if (data < nodePtr->data)
//            nodePtr = nodePtr->left;
//        else
//            nodePtr = nodePtr->right;
//    }
//    return false;
}

template <class T>
bool BinaryTree<T>::search(T data) {
    return _search(data, root);
}




#endif //MOVIES_DATABASE_BINARYTREE_H

//
// Created by Bruce Tieu on 11/18/20.
//

#ifndef MOVIES_DATABASE_BINARYTREE_H
#define MOVIES_DATABASE_BINARYTREE_H

#include <iostream>


template<class T>
class BinaryTree {

public:

    struct TreeNode {
        T data;
        TreeNode *left;
        TreeNode *right;
    };

    BinaryTree();
    void insert(T data, TreeNode* leaf);
    void insert(T data);
    void inorderPrint();
    void inorderPrint(TreeNode* leaf);

private:
    TreeNode *root;
};

template <class T>
BinaryTree<T>::BinaryTree() {
    root = nullptr;
}

template <class T>
void BinaryTree<T>::insert(T data, TreeNode *leaf) {

    if (data < leaf->data){
        if (leaf->left != NULL){
            insert(data, leaf->left);
        } else{
            leaf->left = new TreeNode;
            leaf->left->data = data;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    } else if (data >= leaf->data) {
        if (leaf->right != NULL) {
            insert(data, leaf->right);
        } else{
            leaf->right = new TreeNode;
            leaf->right->data = data;
            leaf->right->right = NULL;
            leaf->right->left = NULL;
        }
    }
}

template <class T>
void BinaryTree<T>::insert(T data) {
    if (root != nullptr) {
        insert(data, root);
    } else {
        root = new TreeNode;
        root->data = data;
        root->left = nullptr;
        root->right = nullptr;
    }
}

template <class T>
void BinaryTree<T>::inorderPrint() {
    inorderPrint(root);
    std::cout << "\n";
}

template <class T>
void BinaryTree<T>::inorderPrint(TreeNode* leaf) {
    if (leaf != nullptr) {
        inorderPrint(leaf->left);
        std::cout << leaf->data << std::endl;
        inorderPrint(leaf->right);
    }
}

//template <class T>
//T* BinaryTree<T>::insertNode(T *root, T data) {
//    if (root == nullptr) {
//        root = getNewNode(data);
//    } else if (data <= root->) {
//        root->left = insertNode(root->left, data);
//    } else if (data >= root->data) {
//        root->right = insertNode(root->right, data);
//    }
//    return root;
//}

//template<class T>
//typename BinaryTree<T>::TreeNode *BinaryTree<T>::insert(TreeNode *root, T data) {
//
////    TreeNode *temp = new TreeNode();
//
//    if (root == nullptr) {
//        root = getNewNode();
//    }
//    else if (data <= temp->data) {
//        insert(root->left);
//    } else
//        insert(root->right);
//
//}



#endif //MOVIES_DATABASE_BINARYTREE_H

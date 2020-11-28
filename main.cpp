//
// Created by Bruce Tieu on 11/10/20.
//


#include <iostream>
#include <string>
#include "BinaryTree.h"
#include "Menu.h"
//#include "Options.h"
//
//class ActorsBST;
//#include "ActorsBST.h"
//#include "ActorsActresses.h"
//#include "ActorsBST.h"
#include "ActorsActresses.h"

using namespace std;

int main()
{
    Menu menu;
    menu.mainMenu();
//    ActorsActresses actorsActresses;
//    actorsActresses.readInFile();
//    BinaryTree<ActorsActresses> tree;
//
//
//    tree.insert(ActorsActresses("1999", "Award", "Winner", "Name", "Fim"));
//    tree.inorderPrint();
//    tree.insertNode(actorsActresses);
//    ActorsActresses actorsActresses("1999", "Award", "Winner", "Name", "Fim");
//    actorsActresses.setYear("1999");
//    tree.insertNode(actorsActresses);
//    BinaryTree<ActorsActresses> actors;
//    TreeNode *root = nullptr;
//    ActorsActresses* root = new ActorsActresses();


//    root = actors.insertNode(root, ActorsActresses("1999", "Award", "Winner", "Name", "Fim"));
//    Database *database1 = new Database();
//    Database *database2;
//
//    Pictures pictures;
//    ActorsActresses actorsActresses;
//    actorsActresses.readInFile();
//
//    database1 = actorsActresses;
//    database1->readInFile();
//
//
//    database1 = &pictures;
//    database1->readInFile();
//
//    database2 = &actorsActresses;
//    database2->readInFile();
//    ifstream infile("actor-actress.csv");
//    string header,year,award, winner, name, film;
//    int records = 0;
//
//    getline(infile, header);
//    cout << "Header\n" << header << endl << endl;
//    while (infile.good())
//    {
//        getline(infile, year, ',');
//        getline(infile,award, ',');
//        getline(infile, winner, ',');
//        getline(infile, name, ',');
//        getline(infile,film);
//        cout << year << endl << award << endl << winner <<endl << name <<endl<<film<<endl;
//        records++;
//        cout << "RECORDS: " << records<<endl << endl;
//    }
//
//    cout << "Records: "<<records <<endl;


    return 0;
}
/*
 * C++ Program on Binary Tree
 * 1. Add Nodes
 * 2. Search Node
 * 3. Perform Inorder
 */
//# include <iostream>
//# include <cstdlib>
//#include<string.h>
//
//using namespace std;
///*
// * Node Declaration
// */
//template <class T>
//class BinaryTree;
//
//class EmployeeInfo
//{
//private:  int empID;
//    char name[50];
//
//
//public:
//
//    EmployeeInfo * left;
//    EmployeeInfo * right;
//
//    EmployeeInfo(int id = 0, char* name = "None" ){
//        this->empID = id;
//        strcpy(this->name, name);
//    }
//
//    void setID(int n){
//        this->empID = n;
//    }
//
//    void setName(char *str){
//        strcpy(name, str);
//    }
//
//    int getID(){
//        return empID;
//    }
//
//    char * getName(){
//        return name;
//    }
//
//    bool operator == (EmployeeInfo& emp){
//
//        if(this->empID==emp.getID() &&
//           (strcmp(this->name, emp.getName())==0))
//        {
//            return true;
//        }
//        else
//        {
//            return false;
//        }
//
//    }
//
//    friend ostream &operator << (ostream &strm, EmployeeInfo &obj)
//    {
//        strm << "ID Number: " << obj.getID() << "\tName: " << obj.getName() << endl;
//        return strm;
//    }
//};
//
//
//template <class T>
//class BinaryTree
//{
//private:
//    EmployeeInfo * root;
//
//public:
//
//    BinaryTree(){
//        root= NULL;
//    }
//
//    void insertNode(T data){
//        insert(root, &data);
//    }
//
//    void insert(T *tree, T *newnode)
//    {
//        if (root == NULL)
//        {
//            root = new EmployeeInfo;
//
//            root->setID(newnode->getID());
//            root->setName(newnode->getName());
//
//            root->left = NULL;
//            root->right = NULL;
//            cout<<"Root Node is Added"<<endl;
//            return;
//        }
//        if (root->getID() == newnode->getID())
//        {
//            cout<<"Element already in the tree"<<endl;
//            return;
//        }
//        if (tree->getID() > newnode->getID())
//        {
//            if (tree->left != NULL)
//            {
//                insert(tree->left, newnode);
//            }
//            else
//            {
//                tree->left = newnode;
//                (tree->left)->left = NULL;
//                (tree->left)->right = NULL;
//                cout<<"Node Added To Left"<<endl;
//                return;
//            }
//        }
//        else
//        {
//            if (tree->right != NULL)
//            {
//                insert(tree->right, newnode);
//            }
//            else
//            {
//                tree->right = newnode;
//                (tree->right)->left = NULL;
//                (tree->right)->right = NULL;
//                cout<<"Node Added To Right"<<endl;
//                return;
//            }
//        }
//    }
//
//
//    void displayInOrder(){
//        inorder(root);
//    }
//
//    void inorder(T *ptr)
//    {
//        if (root == NULL)
//        {
//            cout<<"Tree is empty"<<endl;
//            return;
//        }
//        if (ptr != NULL)
//        {
//            inorder(ptr->left);
//            cout<<"["<<ptr->getID()<<"-"<<ptr->getName()<<"]"<<endl;
//            inorder(ptr->right);
//        }
//    }
//
//
//// Function to check the given key exist or not
//    T* searchNode(int key)
//    {
//// Traverse untill root reaches to dead end
//        while (root != NULL)
//        {
//// pass right subtree as new tree
//            if (key > root->getID())
//                root = root->right;
//
//// pass left subtree as new tree
//            else if (key < root->getID())
//                root = root->left;
//            else
//                return root;// if the key is found return 1
//        }
//        return NULL;
//    }
//
//};
//
////main function starts from here..
//int main()
//{
//    int num = 0;
//    BinaryTree<EmployeeInfo>tree; // create a BinaryTree object
//
//    EmployeeInfo wkr1(1021, "John Williams"); // put data into object
//    tree.insertNode(wkr1); // put object into tree
//    EmployeeInfo wkr2(1057, "Bill Witherspoon");
//    tree.insertNode(wkr2);
//    EmployeeInfo wkr3(2487, "Jennifer Twain");
//    tree.insertNode(wkr3);
//    EmployeeInfo wkr4(3769, "Sophia Lancaster");
//    tree.insertNode(wkr4);
//    EmployeeInfo wkr5(1017, "Debbie Reece");
//    tree.insertNode(wkr5);
//    EmployeeInfo wkr6(1275, "George McMullen");
//    tree.insertNode(wkr6);
//    EmployeeInfo wkr7(1899, "Ashley Smith");
//    tree.insertNode(wkr7);
//    EmployeeInfo wkr8(4218, "Josh Plemmons");
//    tree.insertNode(wkr8);
//
//    cout << "\n\nHere is the workforce:\n\n"; //Display the workforce.
//    tree.displayInOrder();
//
//    cout << "\nEnter an employee number: "; //Get an ID number to search for.
//    cin >> num;
//
//    EmployeeInfo *ptr = tree.searchNode(num); //Search for the employee in the tree.
//
//    if (ptr)
//    {
//        cout << "\nEmployee was found:\n" << *ptr;
//    }
//    else
//    {
//        cout << "\nThat employee was not found.\n\n";
//    }
//    return 0;
//}
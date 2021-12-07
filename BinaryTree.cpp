//
// Created by jshbs on 12/6/2021.
//
#include <iostream>
#include "BinaryTree.h"
using namespace std;


//inserts node into tree
void BinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
    if (nodePtr == nullptr)
        nodePtr = newNode;                          //this is what inserts the node
    else if (newNode->sequence < nodePtr->sequence)
        insert(nodePtr->left, newNode);
    else
        insert(nodePtr->right, newNode);



}

//creates a new node to hold data and passes it to insert function
void BinaryTree::insertNode(string str, int counter)
{
    TreeNode *newNode = nullptr; //pointer to a new node

    //create new node store data in it
    newNode = new TreeNode;
    newNode->sequence = str;
    newNode->count = counter;
    newNode->left = newNode->right = nullptr;

    insert(root, newNode);
}


bool BinaryTree::searchNode(string str)
{
    TreeNode *nodePtr = root;

    while (nodePtr)
    {
        if(nodePtr->sequence == str)      //if found return true
            return true;
        else if (str < nodePtr->sequence) //if str is smaller set nodePtr to left node pointer
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;     //otherwise, set nodePtr to right node pointer
    }
    return false;
}

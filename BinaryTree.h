//
// Created by jshbs on 12/6/2021.
//

#ifndef PROJECT5_BINARYTREE_H
#define PROJECT5_BINARYTREE_H

#include <string>

using namespace std;

class BinaryTree
{
private:
    struct TreeNode
    {
        string sequence; //sequence of chars
        int count;       //number of times the char sequence occurs
        TreeNode *left;  //pointer to left child node
        TreeNode *right; //pointer to right child node
    };

    TreeNode *root; //pointer to the root node

    //private member functions
    void insert(TreeNode *&, TreeNode*&);
    void displayInOrder(TreeNode *) const;

public:
    // constructor
    BinaryTree() {root = nullptr;}

    //tree operations
    void insertNode(string, int );
    bool searchNode(string);
    void displayInOrder() const { displayInOrder(root);}
};

#endif //PROJECT5_BINARYTREE_H

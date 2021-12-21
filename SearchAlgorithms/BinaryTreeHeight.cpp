// This algorithm is for finding the height of a binary tree

// We start at the root node of the tree and count the child nodes, if no child nodes, the height is 0
// Then recursively call all the nodes from the left and right subtree of the root node to calculate the height

#include <iostream>
#include <algorithm>

using namespace std;

// Each node will have a pointer to a left and right child
class node {
    public: 
        int data;
        node* left;
        node* right;
};

int maxDepth(node* node) {
    if (node == NULL) {
        return -1;
    } else {
        // compute the depth of each sub tree
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);

        // use the larger one
        if (leftDepth > rightDepth) {
            return (leftDepth + 1);
        } else {
            return (rightDepth + 1);
        }
    }
}

// helper function to allocate a new node with the given data and NULL left and right pointers
node* newNode(int data) {
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return Node;
}
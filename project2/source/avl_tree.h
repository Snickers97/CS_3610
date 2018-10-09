#ifndef AVL_TREE_H
#define AVL_TREE_H

//Structure of the nodes making up the AVL tree
struct BinaryNode {
    BinaryNode(const int key) : key(key), left(NULL), right(NULL) {}

    ~BinaryNode() {
        delete left;
        delete right;
        left = right = NULL;
    }

    int key;
    BinaryNode *left, *right;
};

//Class for the AVL tree composed of BinaryNodes
class AVLTree {

public:
    AVLTree() : root(NULL) {}
    ~AVLTree() {
        delete root;
    }

    //Public, user-facing function to insert a new node
    void insert(const int key);
    //Function to remove node
    void remove(const int key);
    //Function to print node values or heights in order
    void print(const char c);


private:
    //Internal function to recursively insert the new node in the correct place
    BinaryNode* insert(const int key, BinaryNode* node);
    //Function to remove a node and balance the tree correctly
    BinaryNode* remove(const int key, BinaryNode* node);
    //Recursive inorder value print function
    void print_val(BinaryNode* node);
    //Recursive inorder height print function
    void print_height(BinaryNode* node);
    //Return the height of the node
    int height(BinaryNode* node);
    //Balance the tree at this node
    void balance(BinaryNode* node);

    BinaryNode* root;
};

#endif

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
    //Rotate left at this node
    BinaryNode* rotate_left(BinaryNode* node);
    //Rotate right at this node
    BinaryNode* rotate_right(BinaryNode* node);
    //Remove the node with key value
    BinaryNode* remove_node(const int key, BinaryNode* node);
    //Balance from the left
    BinaryNode* balance_left(BinaryNode* node);
    //Balance from the right
    BinaryNode* balance_right(BinaryNode* node);

    BinaryNode* root;
};

#endif

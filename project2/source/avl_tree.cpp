#include <iostream>
#include "avl_tree.h"
using namespace std;

//The public insert function
//Calls the private function to recursively add more nodes
void AVLTree::insert(const int key) {
    this->root = insert(key, this->root);
}

//The public remove function; calls the recursive remove function
void AVLTree::remove(const int key){
    //this->root = remove(key, this->root);
}

//The public print function
//Calls either print_height or print_val depending on the input
void AVLTree::print(const char c){
    switch(c){
        case 'p':
            //Call the value print function
            print_val(this->root);
            break;
        case 'h':
            //Call the height print function
            print_height(this->root);
            break;
        default:
            break;
    }
    //End the line after all nodes have been printed
    cout<<endl;
}

//The private insert function for adding nodes in the correct position
BinaryNode* AVLTree::insert(const int key, BinaryNode* node) {
    //Node does not exist; create new node
    if (node == NULL) {
        return new BinaryNode(key);
    }
    //Node already exists, duplicates not allowed
    if(node->key == key)
        return node;
    //Key is less than current node, move to left node
    if(key < node->key) {
        if(node->left == NULL) {
            node->left = new BinaryNode(key);
        }
        else {
            node->left = insert(key, node->left);
        }
    }
    //Key is greater than current node, move to right node
    else {
        if(node->right == NULL) {
            node->right = new BinaryNode(key);
        }
        else{
            node->right = insert(key, node->right);
        }
    }
    //Need to re-balance the tree if subtree heights differ by more than 1
    if(abs(height(node->left) - height(node->right)) > 1){
        balance(node);
    }

    return node;

}

//The function for printing node values in order
void AVLTree::print_val(BinaryNode* node){
    if(node == NULL){
        return;
    }
    print_val(node->left);
    cout<<node->key<<" ";
    print_val(node->right);
}

//The function for print the node heights in order
void AVLTree::print_height(BinaryNode* node){
    if(node == NULL)
        return;
    print_height(node->left);
    cout<<height(node)<<" ";
    print_height(node->right);
}

//The Tree function to return the height of a node
int AVLTree::height(BinaryNode* node){
    if(node == NULL)
        return 0;
    int h = 1;
    //If node has no children, its height is 1
    if(node->left == NULL && node->right == NULL)
        return h;
    //If node only has one child, its height is 1 + child height
    else if(node->right == NULL)
        return h + height(node->left);
    else if(node->left == NULL)
        return h + height(node->right);
    //If node has two children, its height is 1 + height of the tallest child
    else{
        return h + max(height(node->left), height(node->right));
    }
}

void AVLTree::balance(BinaryNode* node){
    if(height(node->left) > height(node->right)){
        BinaryNode* ptr = node->left;
        ptr->right = node;
    }
    else{
        BinaryNode* ptr = node->right;
        ptr->left = node;
    }
}

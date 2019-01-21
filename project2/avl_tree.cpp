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
    this->root = remove_node(key, this->root);
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
        node->left = insert(key, node->left);
        //Balance from the left
        if((height(node->left) - height(node->right)) > 1){
            node = balance_left(node);
        }
    }
    //Key is greater than current node, move to right node
    else {
        node->right = insert(key, node->right);
        //Balance from the right
        if((height(node->right) - height(node->left)) > 1){
            node = balance_right(node);
        }
    }
    //Balance from the left
    if((height(node->left) - height(node->right)) > 1){
        node = balance_left(node);
    }
    //Balance from the right
    if((height(node->right) - height(node->left)) > 1){
        node = balance_right(node);
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

//Rotate left at node
BinaryNode* AVLTree::rotate_left(BinaryNode* node){
    if(node == NULL || node->right == NULL)
        cout<<"Error"<<endl;
    else{
        BinaryNode* ptr = node->right;
        node->right = ptr->left;
        ptr->left = node;
        node = ptr;
        return node;
    }
}

//Rotate right at node
BinaryNode* AVLTree::rotate_right(BinaryNode* node){
    if(node == NULL || node->left == NULL)
        cout<<"Error"<<endl;
    else{
        BinaryNode* ptr = node->left;
        node->left = ptr->right;
        ptr->right = node;
        node = ptr;
        return node;
    }
}

//Remove the node with key value
//Warning: this function is horrifically ugly. It works but don't look at it
BinaryNode* AVLTree::remove_node(const int key, BinaryNode* node){
    //edge case
    if(node == NULL)
        return NULL;
    //Node is found, delete it
    if(node->key == key){
        if(node->left==NULL && node->right==NULL){
            delete node;
            return NULL;
        }
        else if(node->right == NULL){
            node = node->left;
            delete node->left;
            return node;
        }
        else if(node->left == NULL){
            node = node->right;
            delete node->right;
            return node;
        }
        else{ //Node to be removed has two children. The complex case
            //I checked for this to prevent the tree from getting lopsided
            //after multiple deletions of the root
            if(height(node->right) >= height(node->left)){
                BinaryNode* ptr = node->right;
                BinaryNode* prev = node;
                while(ptr->left != NULL){ //find the inorder successor of node
                    prev = ptr;
                    ptr = ptr->left;
                }
                if(prev == node){ //in this case, successor is right after node
                    BinaryNode* tmp = node->left;
                    node = ptr;
                    node->left = tmp;
                }
                else{ //usual case, successor is farther down the tree
                    node->key = ptr->key;
                    prev->left = NULL;
                }
            }
            else{ //same as line 154 but sides are reversed
                BinaryNode* ptr = node->left;
                BinaryNode* prev = node;
                while(ptr->right != NULL){
                    prev = ptr;
                    ptr = ptr->right;
                }
                if(prev == node){
                    BinaryNode* tmp = node->right;
                    node = ptr;
                    node->right = tmp;
                }
                else{
                    node->key = ptr->key;
                    prev->right = NULL;
                }
            }
        }
    }
    else if(key < node->key && node->left != NULL){ //Not the node; go left
        node->left = remove_node(key, node->left);
    }
    else if(key > node->key && node->right != NULL){ //Not the node; go right
        node->right = remove_node(key, node->right);
    }
    //Balance from the left
    if((height(node->left) - height(node->right)) > 1){
        node = balance_left(node);
    }
    //Balance from the right
    if((height(node->right) - height(node->left)) > 1){
        node = balance_right(node);
    }
    return node;
}

//Balances the tree from the left
BinaryNode* AVLTree::balance_left(BinaryNode* node){
    BinaryNode* ptr = node->left;
    if((height(ptr->left) - height(ptr->right) > 1)){
        node = rotate_right(node);
    }
    else if((height(ptr->right) - height(ptr->left)) > 1){
        ptr = rotate_left(ptr);
        node->left = ptr;
        node = rotate_right(node);
    }
    return node;
}

//Balances the tree from the right
BinaryNode* AVLTree::balance_right(BinaryNode* node){
    BinaryNode* ptr = node->right;
    if((height(node->right) - height(node->left)) > 1){
        node = rotate_left(node);
    }
    else if((height(node->left) - height(node->right)) > 1){
        ptr = rotate_right(ptr);
        node->right = ptr;
        node = rotate_left(node);
    }
    return node;
}

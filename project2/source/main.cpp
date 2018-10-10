#include <iostream>
#include "avl_tree.h"
using namespace std;

int main(int argc, char** argv) {

    AVLTree tree;

    char option;
    int key;

    cout<<"i:         insert node\n";
    cout<<"r:         remove node\n";
    cout<<"h:         print the height of each node in order\n";
    cout<<"p:         print the value of each node in order\n";
    cout<<"q:         quit\n";

    do {
        cin >> option;
        switch(option) {
            case 'i':
                cin >> key;
                tree.insert(key);
                break;
            case 'r':
                cin >> key;
                 tree.remove(key);
                break;
            case 'h':
                tree.print('h');
                break;
            case 'p':
                tree.print('p');
                break;
            default:
                break;
        }
    } while(option != 'q');
}

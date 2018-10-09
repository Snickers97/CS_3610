#include <iostream>
#include <stack>

using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

void FillTree(node *ptr);
void inorder(node *ptr);
int singleparent(node *ptr);
int singleP_iterative(node *ptr);

int main(){
    node *root = new node;
    node *ptr = root;
    int num;
    cout<<"Root: ";
    cin>>num;
    ptr->data = num;
    FillTree(ptr);
    //inorder(ptr);
    cout<<"Singles: "<<singleparent(ptr)<<endl;
    cout<<"Singles: "<<singleP_iterative(ptr)<<endl;

    return 0;

}

void FillTree(node *ptr){
    int num;
    cout<<"Left: ";
    cin>>num;
    if(num != 0){
        ptr->left = new node;
        ptr->left->data = num;
        FillTree(ptr->left);
    }
    cout<<"Right: ";
    cin>>num;
    if(num != 0){
        ptr->right = new node;
        ptr->right->data = num;
        FillTree(ptr->right);
    }
    return;

}

void inorder(node *ptr){
    if(ptr != NULL){
        inorder(ptr->left);
        cout<<ptr->data<<endl;
        inorder(ptr->right);
    }
}

int singleparent(node *ptr){
    int count = 0;
    if(ptr == NULL)
        return count;
    if(ptr->left == NULL && ptr->right == NULL)
        return count;
    else if(ptr->right == NULL){
        count++;
        return count + singleparent(ptr->left);
    }
    else if(ptr->left == NULL){
        count++;
        return count + singleparent(ptr->right);
    }
    else{
        count += singleparent(ptr->left);
        count += singleparent(ptr->right);
    }
    return count;
}

int singleP_iterative(node *ptr){
    if(ptr == NULL)
        return 0;
    node *current = ptr;
    stack<node *> s;
    int count = 0;
    while(current != NULL || !s.empty()){
        if(current != NULL){
            s.push(current);
            current = current->left;
        }
        else{
            current = s.top();
            s.pop();
            if(current->left != NULL && current-> right == NULL)
                count++;
            if(current->left == NULL && current-> right != NULL)
                count++;
            current = current->right;
        }
    }
    return count;
}

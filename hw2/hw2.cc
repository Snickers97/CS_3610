#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*struct binaryTreeNode{
    int info;
    binaryTreeNode<elemType> *llink;
    binaryTreeNode<elemType> *rlink;
};

struct binaryTreeNode {
    binaryTreeNode(const int key) : key(key), llink(NULL), rlink(NULL) {}

    ~binaryTreeNode() {
        delete llink;
        delete rlink;
        llink = rlink = NULL;
    }

    int key;
    binaryTreeNode *llink, *rlink;
};

int leafcount(binaryTreeNode* root);
int nr_leafcount(binaryTreeNode* root);

int main(){
    binaryTreeNode* root = new binaryTreeNode(5);
    root->llink = new binaryTreeNode(4);
    root->rlink = new binaryTreeNode(7);
    binaryTreeNode* ptr = root->rlink;
    ptr->rlink = new binaryTreeNode(50);
    ptr->llink = new binaryTreeNode(25);
    cout<<leafcount(root)<<endl;
    cout<<nr_leafcount(root)<<endl;
    return 0;
}

int leafcount(binaryTreeNode* root){
    if(root == NULL)
        return 0;
    else if(root->llink == NULL && root->rlink == NULL)
        return 1;
    else if(root->rlink == NULL)
        return leafcount(root->llink);
    else if(root->llink == NULL)
        return leafcount(root->rlink);
    else{
        return leafcount(root->llink) + leafcount(root->rlink);
    }
    return 0;
}

int nr_leafcount(binaryTreeNode* root){
    binaryTreeNode* ptr = root;
    stack<binaryTreeNode*> s;
    int count = 0;
    while(ptr != NULL || !s.empty()){
        if(ptr != NULL){
            s.push(ptr);
            ptr = ptr->llink;
        }
        else{
            ptr = s.top();
            if(ptr->llink == NULL && ptr->rlink == NULL)
                count++;
            s.pop();
            ptr = ptr->rlink;
        }
    }
    return count;
}

void heapify(int low, int high,int h[]){
    int largeIndex;
    int count = 0;
    int temp = h[low]; //copy the root node of the subtree
    largeIndex = 2 * low + 1;  //index of the left child
    while (largeIndex <= high){
        count++;
        if (largeIndex < high)
            count++;
            if (h[largeIndex]< h[largeIndex + 1])
                count++;
                largeIndex = largeIndex + 1; //index of the largest//child
        if (temp > h[largeIndex]){ //subtree is already in a heap
            count++;
            break;
        }
        else{
            h[low]= h[largeIndex]; //move the larger child//to the root
            low = largeIndex; //go to the subtree to restore the heap
            largeIndex = 2 * low + 1;
        }
    }
    //end while
    h[low]= temp; //insert temp into the tree, that is, list
    cout<<"Count: "<<count<<endl;
}
//end heapify

void buildHeap(int h[]){
    for (int index = 18 / 2 - 1; index >= 0; index--)
        heapify(index, 18 - 1, h);
}

void heapSort(int list[]){
    int temp;
    buildHeap(list);
    int i = 0;
    for (int lastOutOfOrder = 18 - 1; lastOutOfOrder >= 0; lastOutOfOrder--){
        if(i == 1)
            break;
        temp = list[lastOutOfOrder];
        list[lastOutOfOrder]= list[0];
        list[0]= temp;
        heapify(0, lastOutOfOrder - 1, list);
        i++;
    }
    //end for
}

int main(){
    int h[18] = {100, 85, 94, 47, 72, 82, 76, 30, 20, 60, 65, 50, 45, 17, 35, 14, 28, 5};
    heapSort(h);
    for(int i =0; i< 18; i++){
        cout<<h[i]<<" ";
    }
    cout<<endl;
    return 0;
}*/

int r_seqsearch(vector<int> nums, int loc, int item){
    if(loc == nums.size())
        return -1;
    if(nums[loc] == item)
        return loc;
    else
        return r_seqsearch(nums, loc+1, item);

}

int main(){
    vector<int> nums = {2,7,89,22,75,66,1024};
    cout<<r_seqsearch(nums, 0, 1024)<<endl;
    return 0;
}

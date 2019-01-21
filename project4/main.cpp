#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int partition(vector<int>& list, int first, int last) {
    // The pivot should be the median of the
    // first, middle, and last elements.
    int middle = (last+first)/2;
    int pivot = max(min(list[first],list[middle]),min(max(list[first],list[middle]),list[last]));
        //find the median of first, middle, and last elements as pivot
    if(list[last] == pivot)
        //Swap pivot element with first element
        swap(list[first],list[last]);
    else if(list[middle] == pivot)
        swap(list[middle],list[first]);
    int smallindex = first;
        //Initialize small index to the pivot
    for(int index=first+1; index<=last; index++){
        //Sort the list
        if(list[index] < pivot){
            smallindex++;
            swap(list[index],list[smallindex]);
        }
    }
    swap(list[smallindex],list[first]);
    return smallindex;
}

void quicksort(vector<int>& list, int first, int last) {
    //The list is sorted if there is only one element
    if(last-first <=1)
        return;
    int j = partition(list, first, last);
    quicksort(list,first,j-1);
        //Sort the left half
    quicksort(list,j+1,last);
        //Sort the right half
}

void multiway_merge(
    vector<vector<int> >& input_lists, vector<int>& output_list
){
    priority_queue<int, vector<int>, greater<int>> min_heap;
        //A min priority queue to produce the smallest from each list
    std::vector<int>::iterator it[input_lists.size()-1];
    for(int i = 0; i < input_lists.size(); i++){
        it[i] = input_lists[i].begin();
        min_heap.push(*it[i]);
        //Iterators for each input list
    }
    int count = 0;
    while(!min_heap.empty()){
        output_list[count++] = min_heap.top();
            //Assign each element to the output list in order
        for(int i = 0; i < input_lists.size(); i++){
            if(min_heap.top() == *it[i]){
                    //Find out which input list the min element came from
                min_heap.pop();
                    //Remove the min element from the heap
                it[i]++;
                    //Move to the next element in the list of the min element
                if(it[i] != input_lists[i].end())
                    min_heap.push(*it[i]);
                break;
            }
        }
    }
}

int main(int argc, char** argv) {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > input_lists(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> input_lists[i][j];
        }
    }

    // Quicksort k sublists
    for (int i = 0; i < input_lists.size(); ++i)
        quicksort(input_lists[i], 0, m-1);

    // Merge n input sublists into one sorted list
    vector<int> output_list(n * m);
    multiway_merge(input_lists, output_list);

    for (int i = 0; i < output_list.size(); ++i)
        cout << output_list[i] << " ";
    cout << endl;

    return 0;
}

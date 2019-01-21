#include <iostream>
#include <queue>
using namespace std;

//Finds the closest city that hasn't been processed yet
int mindistance(int n, int path[], bool found[]){
    int min = INT32_MAX;
    int min_index;
    for(int i = 0; i < n; i++){
        if(found[i] == false and path[i] <= min){
            min = path[i];
            min_index = i;
        }
    }
    return min_index;
}

//Function implementing dijkstra's algorithm
void dijkstra(int n, string *cities, vector<vector<int>> dist){
    int path[n];    //Array storing shortest distance from start to each city
    bool found[n];  //Marks whether path to this city has been found
    for(int i = 0; i < n; i++){
        //Initialize all paths to infinity and marks paths as not found
        path[i] = INT32_MAX;
        found[i] = false;
    }
    path[0] = 0;
        //The distance from the first city to itself is zero

    for(int i = 0; i < n; i++){
        int u = mindistance(n, path, found);
            //u is the closest city that hasn't been found
        found[u] = true;
        for(int j = 0; j < n; j++){
            if(!found[j] && dist[u][j] && path[u] != INT32_MAX && path[u]
            + dist[u][j] < path[j]){
                path[j] = path[u] + dist[u][j];
                    //Update the city distance
            }
        }
    }

    cout<<path[n-1]<<endl;
        //Print the distance between the first and last city


}

int main(){
    int n,k;
    cin>>k;
    while(k != 0){  //Loop for running each of the test cases
        cin>>n;
        string cities[n];
        for(int i = 0; i < n; i++){  //Loop for reading in city names
            cin>>cities[i];
        }
        vector<vector<int>> dist;
        for(int i = 0; i < n; i++){ //Loop for reading in distances
            vector<int> in;
            for(int j = 0; j < n; j++){
                int tmp;
                cin>>tmp;
                in.push_back(tmp);
            }
            dist.push_back(in);
        } //End distances loop
        dijkstra(n, cities, dist);
        k--;
    }   //End test case loop
    return 0;
}

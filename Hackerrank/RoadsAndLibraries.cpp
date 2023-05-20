#include <iostream>
#include <vector>
#include <list>

using namespace std;

void DFS(int i, int &r, vector<bool> &visited, vector<vector<int>> &citiesNear){
    visited[i]=true;
    for(int city: citiesNear[i]){
        if(!visited[city]){
            r++;
            DFS(city, r, visited, citiesNear);
        }
    }
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    //library build cost is less 
    if (c_lib <= c_road) return n*c_lib;

    //road build cost is less
    vector<vector<int>> citiesNear(n+1); //adjecancy list format of the graph
    vector<bool> visited(n+1,false);
    int r=0; //number of roads 
    long cost = 0;
    
    for(vector<int> city : cities){
        citiesNear[city[0]].push_back(city[1]);
        citiesNear[city[1]].push_back(city[0]);
    }

    for(int i=1; i<=n; i++){
        if(!visited[i]){
            //calculate cost for a connected segment of the graph
            DFS(i, r, visited, citiesNear);
            cost += r*c_road + c_lib;
            r = 0; //reset r to 0
        }
    }
    return cost;    
}

int main(){
    int n = 6;
    int c_lib = 5;
    int c_road = 2;
    vector<vector<int>> cities {{1, 3}, {3, 4}, {2, 4}, {1, 2}, {2, 3}, {5, 6}};
    //vector<vector<int>> cities {{1, 2}, {3, 4}, {5, 6},{7, 2}, {7, 4}, {7, 6}};
    //vector<vector<int>> cities {{1, 2}, {1, 3}, {1, 4}};
    //vector<vector<int>> cities {};


    cout<<roadsAndLibraries(n, c_lib, c_road, cities)<<endl;
}

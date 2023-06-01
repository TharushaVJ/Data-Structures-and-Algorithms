#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printVec(vector<int> v){
    cout<<"[ ";
    for(int n : v){
        cout<< n << ", ";
    }
    cout<<"]";
}

void print2D(vector<vector<int>> v){
    cout<< "[ ";
    for(vector<int> u: v){
        printVec(u);
        cout<<", ";
    }
    cout <<"]"<< endl;;
    
}

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<vector<int>> adj(n);
    queue <int> q;
    vector<int> distances(n,-1);
    vector<int> cost(n-1,-1);

    for(vector<int> edge: edges){
        adj[edge[0]-1].push_back(edge[1]);
        adj[edge[1]-1].push_back(edge[0]);
    }

    q.push(s);
    distances[s-1] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(int neighbour: adj[node-1]){
            if (distances[neighbour-1]==-1){
                q.push(neighbour);
                distances[neighbour-1] = distances[node-1] + 6;
                if(neighbour-s<0) cost[neighbour-1] = distances[neighbour-1]; 
                else cost[neighbour-2] = distances[neighbour-1];
            }
        }
    }
    return cost;
}

int main (){
    int n = 6;
    int m = 5;
    vector<vector<int>> edges { {1, 2}, {1, 3}, {3, 4}, {4, 5}};
    int s = 6;

    vector<int> distances = bfs(n,m,edges,s);
    cout<<"[ ";
    for(int distance: distances){
        cout<<distance<<", ";
    }
    cout<<" ]";
    return 0;
}
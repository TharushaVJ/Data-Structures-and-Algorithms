#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//print a vector
void printVec(vector<int> v){
    cout<<"[ ";
    for(int n : v){
        cout<< n << ", ";
    }
    cout<<"]";
}

//print a 2D vector
void print2D(vector<vector<int>> v){
    cout<< "[ ";
    for(vector<int> u: v){
        printVec(u);
        cout<<", "<<endl;;
    }
    cout <<"]"<< endl;;
    
}

//Prim's Algorithm
vector<vector<int>> primsMST(vector<vector<int>> G, int s){
    vector<int> edge (3);

    //{previousNode, node, edgeWeight} - MST
    vector<vector<int>> MST(6, edge);

    //{edgeWeight, node, previousNode} - edges of unvisited nodes
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; 

    vector<bool> visited(6,false);
    pq.push({0, s, NULL});

    while(!pq.empty()){
        vector<int> minimumEdge  = pq.top(); //{edgeWeight, node, previousNode}
        int pole = minimumEdge[1];
        pq.pop();

        //set MST edge
        if(!visited[pole]){
            MST[pole] = {minimumEdge[2], pole, minimumEdge[0]}; //{previousNode, node, edgeWeight}
        }

        visited[pole]=true;

        for(int i=0; i<6; i++){
            if(G[pole][i]!=0 && !visited[i]){
                pq.push({G[pole][i], i, pole}); //{nodeCost, node, previousNode}
            }
        }   
    }
    return MST;
}

//Print edges with the edge weight in the MST
void printMST(vector<vector<int>> MST){
    cout<<"Edge  : Weight"<< endl;
    cout<<"--------------"<< endl;
    for(int i=1; i<6; i++){
        cout << MST[i][0] << " - " << MST[i][1] << " : " << MST[i][2] << endl;
    }
    cout<<"--------------"<< endl;
}

int main(){
    vector<vector<int>> adjMatrix = {
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {1, 0, 5, 0, 4, 0}
    };

    vector<vector<int>> MST = primsMST(adjMatrix, 0);
    printMST(MST);
}
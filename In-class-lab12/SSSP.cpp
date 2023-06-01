#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INFINITY 9999

//print a vector
void printVec(vector<int> v){
    cout<<"[ ";
    for(int n : v){
        cout<< n << ", ";
    }
    cout<<"]";
    cout<<"\n";
}

//find the average of the vector
double avgVec(vector<int> n){
    double total = 0;
    for(auto i=0; i<n.size(); i++) total += n[i];
    double avg = total / (n.size()-1); 
    return avg;   
}

//edge relaxation
void edge_relax(int u, int v, vector<int> &distance, vector<vector<int>> weight){
    int tentativeDistance = distance[u] + weight[u][v];
    if(distance[v]> tentativeDistance) distance[v] = tentativeDistance;
}

//Dijkstra's algorithm
vector<int> Dijkstra(vector<vector<int>> weight, int s){
    vector<int> distance(6); // tentative distances from City S to other cities
    for(int i=0; i<6; i++){
        if(i==s) distance[i] = 0; //set distance to city S as 0
        else distance[i] = INFINITY; //set all other distances to infinity
    }

    //priority queue with a min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    vector<bool> visited(6,false);

    pq.push(make_pair(distance[0], s)); //add the staring node to pq

    while(!pq.empty()){
        pair<int, int> top = pq.top(); 
        int city = top.second; //extract the city with the minimum distance
        pq.pop();
        visited[city] = true;

        for(int v=0; v<6; v++){
            if(weight[city][v]!=0 && !visited[v]) {
                edge_relax(city, v, distance, weight);
                pq.push(make_pair(distance[v], v)); //push the adjacent vertices to pq
            }
        }

    }
    return distance;
}

int main(){
    vector<vector<int>> cityWeights {{0,10,0,0,15,5}, 
                                     {10,0,10,30,0,0}, 
                                     {0,10,0,12,5,0}, 
                                     {0,30,12,0,0,20}, 
                                     {15,0,5,0,0,0},
                                     {5,0,0,20,0,0}};
    
    for(int s=0; s<6; s++){
        cout<<"Origin: City "<< s << endl;
        cout<<"City #: Time taken"<<endl;
        cout<<"------------------"<<endl;
        
        vector<int> distance = Dijkstra(cityWeights, s);
        for(int i=0; i<6; i++){
            cout << "City "<< i << ": " << distance[i] << endl;
        }

        cout<<"------------------"<<endl;
        cout<<"Average time taken: "<< avgVec(distance)<<endl;
        cout<<"\n";
    }

}
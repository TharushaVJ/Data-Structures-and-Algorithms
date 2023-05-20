#include <iostream>
#include <vector>
#include <list>

using namespace std;

int minimum(int l, int r){
    if(l<r) return l;
    return r;
}

class HackerLand{
    int n;
    vector<list<int>> citiesNear;
    
public:
    HackerLand(int n){
        this->n=n;
        citiesNear.resize(n);
    }
    void addcity(vector<int> cityNear){
        citiesNear[cityNear[0]-1].push_back(cityNear[1]);
        citiesNear[cityNear[1]-1].push_back(cityNear[0]);
    }
    void BFS(int s, vector<bool> visited,int c_lib,int c_road,int &l,int &r){
        list<int> q;

        q.push_back(s);
        visited[s-1] = true;

        while(!q.empty()){
            s = q.front();
            q.pop_front();
            l+=c_lib;
            for (int cityNear : citiesNear[s-1]){
                if (!visited[cityNear-1]){
                    q.push_back(cityNear);
                    r+=c_road;
                    visited[cityNear-1] = true;
                }
            }
            r+=c_lib;
        }
    }
};

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    HackerLand H(n);
    vector<bool> visited(n,false);
    int l=0;
    int r=0;
    
    for(vector<int> city : cities) H.addcity(city);
    
    for(int i=1; i<=n; i++){
        if(!visited[i-1]) H.BFS(i,visited,c_lib,c_road,l,r);
    }
    return minimum(l,r);
    
}

int main(){
    int n = 3;
    int c_lib = 2;
    int c_road = 1;
    vector<vector<int>> cities {{1, 2}, {3, 1}, {2, 3}};

    cout<<roadsAndLibraries(n, c_lib, c_road, cities)<<endl;
}

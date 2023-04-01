#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> closestNumbers(vector<int> arr) {
    sort(arr.begin(),arr.end());
    vector<int> ad;//array for adjecent integers giving the smallest absolute difference
    int sad = abs(arr[1]-arr[0]); //smallest absolute difference(sad)
    ad.insert(ad.end(),arr.begin(),arr.begin()+2); //insert the adjecent numbers that gives the 'sad' to 'ad' array

    for(size_t i=1; i<arr.size(); i++){
        int adtemp = abs(arr[i+1]-arr[i]);

        //if a new 'sad' is found clears the array and adds the new adjecent numbers that gives the new 'sad' to the 'ad' array
        if(sad > adtemp){ 
            sad = adtemp;
            ad.clear();
            ad.push_back(arr[i]);
            ad.push_back(arr[i+1]);
        }
        //if adjecent numbers found with the same 'sad' adds them to the 'ad' array
        else if(sad==adtemp){ 
            ad.push_back(arr[i]);
            ad.push_back(arr[i+1]);
        }
    }
    return ad;
}

int main(){
    vector<int> arr{-20, -3916237, -357920, -3620601, 7374819, -7330761, 30, 6246457, -6461594, 266854, -520, -470};
    vector<int> result = closestNumbers(arr);
    for(size_t i=0; i<result.size(); i++){
        cout<< result[i]<<" ";
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimum(int x, int y){
    if (x<y) return x;
    else return y;
}

//sort the vector in ascending order
// void ascSort(vector<pair<int,int>> arr) {
//     sort(arr.begin(),arr.end());
// } 

//sort the vector in descending order
// void dscSort(vector<pair<int,int>> arr){
//     sort(arr.rbegin(),arr.rend());
// }

//int lilysHomework(vector<int> arr) {
//     int asc = 0; //ascending swap count
//     for(size_t i=0; i<arr.size(); i++){
//         //find minimum than arr[i]
//         int* min = &arr[i];
//         for(size_t j=i+1; j<arr.size(); j++){
//             if(*min>arr[j]) min = &arr[j];
//         }
//         //swap if minimum than arr[i] found
//         if(min != &arr[i]){
//             int temp_min = arr[i];
//             arr[i] = *min;
//             *min = temp_min;
//             asc++;
//         }    
//     }
    
//     int dsc = 0; //descending swap count
//     for(size_t i=0; i<arr.size(); i++){
//         //find maximum than arr[i]
//         int* max = &arr[i];
//         for(size_t j=i+1; j<arr.size(); j++){
//             if(*max<arr[j]) max = &arr[j];
//         }
//         //swap if maximum than arr[i] found
//         if(max != &arr[i]){
//             int temp_max = arr[i];
//             arr[i] = *max;
//             *max = temp_max;
//             dsc++;
//         }    
//     }
//     return minimum(asc,dsc); //return the minimum swap count between descending and ascending
// }
   
int lilysHomework(vector<int> arr){
    size_t n = arr.size();
    vector<pair<int,int>> asc_check, dsc_check;
    
    for(size_t i=0; i<n; i++){
        asc_check.push_back({arr[i], i}); 
        dsc_check.push_back({arr[i], i});
    }
    
    //for ascending order
    int asc_swaps = 0; //minimum swap count for ascending order
    sort(asc_check.begin(),asc_check.end());//sorted in the ascending order

    for (size_t i=0; i<n; i++){
        size_t index1 = asc_check[i].second; //index of the element in arr
        if (index1!=i) {
            swap(asc_check[i],asc_check[index1]);
            asc_swaps++;
            i--;
        }
    }
    
    //for descending order
    int dsc_swaps = 0; //minimum swap count for descending order
    sort(dsc_check.rbegin(),dsc_check.rend());//sorted in the descending order

    for (size_t i=0; i<n; i++){
        size_t index2 = dsc_check[i].second; //index of the element in arr
        if (index2!=i){
            swap(dsc_check[i],dsc_check[index2]);
            dsc_swaps++;
            i--;
        }
    }
    
    return minimum(dsc_swaps,asc_swaps);
    
}
int main(){
    vector<int> arr{3,4,2,5,1};
    int result = lilysHomework(arr);
    cout << result ;
    return 0;
}
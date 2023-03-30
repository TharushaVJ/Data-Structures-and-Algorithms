#include <iostream>
#include <vector>

using namespace std;

void print_arr(vector<int> arr);

void Sort(vector<int> arr, int n, size_t first, size_t last){
    print_arr(arr);
    cout << n<<last<<first;
    size_t mid = first + (last - first)/2;

    int index = 0;
    for (index; index < arr.size(); index++){
        if (arr[index] > n){
            break;
        }
    }
    cout << index << endl;
    arr.insert(arr.begin()+index-1, n);
    // if (first == last){
    //     if (arr[first] < n){
    //         //create iterator pointing to 1 position
    //         auto itPos = arr.begin()+ first +1;
    //         //insert n at the 1 position
    //         arr.insert(itPos,n);
    //     }
    //     else if (arr[first] > n){
    //         //create iterator pointing to -1 position
    //         auto itPos = arr.begin() + first -1;
    //         //insert n at the -1 position
    //         arr.insert(itPos,n);
    //     }
    // }
    // else if (arr[mid] == n){
    //     //create iterator pointing to mid+1 position
    //     auto itPos = arr.begin() + mid+1;
    //     //insert n at the mid+1 position
    //     arr.insert(itPos,n);
    // }

    // else if (arr[mid] < n){
    //     Sort(arr, n, mid + 1, last);
    // }
    // else if (arr[mid] > n){
    //     Sort(arr, n, first, mid -1);
    // }
}

void print_arr(vector<int> arr){
    cout << "{";
    for (int i = 0; i<arr.size()-1; i++){
        cout << arr[i] << ", ";
    }
    cout << arr[arr.size()-1] << "}";
}
 
int main(){
    int n; //input
    vector<int> strm; //stream of integers

    cout << "Enter integer (enter (-1) to exit): ";
    cin >> n;
    strm.insert(strm.begin(),n);
    print_arr(strm);

    // while (n!=-1){
    //     cin >> n;
    //     size_t sz = strm.size();
    //     Sort(strm, n, 0, sz-1);

    //     if (sz%2!=0){
    //         print_arr(strm);
    //         cout << "  ";
    //         size_t mid1 = strm.size()/2;
    //         printf("%.1f\n",strm[mid1+1]);
    //     }

    //     else{
    //         print_arr(strm);
    //         cout << "  ";
    //         size_t mid2 = strm.size()/2;
    //         double median = (strm[mid2]+strm[mid2+1])/2;
    //         printf("%.1f\n",median);
    //     }    
       
        
    //}
    while (true){
        cin >> n;
        if (n == -1)
        {
            break;
        }
        
        
        Sort(strm, n, 0, strm.size()-1);
        print_arr(strm);

    }

    return 0;
}
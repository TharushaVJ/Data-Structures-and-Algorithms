#include <iostream>
#include <vector>
//#include <algorithm>

using namespace std;
  
// function to heapify the tree
void heapify(vector<int> &arr, size_t n, int root)
{
   // build heapify
   int largest = root;
   int l = 2*root +1;
   int r = 2*root +2;

   //left larger than parent
   if (l < n && arr[l]> arr[largest]){
      largest = l;
   }

   //right larger than parent
   if (r < n && arr[r]> arr[largest]){
      largest = r;
   }

   //parent is not the largest then swap
   if (largest != root){
      swap(arr[root], arr[largest]);
      heapify(arr, n, largest);   
   }
}
  
// implementing heap sort
void heapSort(vector<int> &arr, size_t n)
{
   // build heap
   for (int i = n/2-1; i>=0; i--){
      heapify(arr, n, i);
   }
  
   // extracting elements from heap one by one
   for (int i = n-1; i>=0; i--){
      //swap root with last element
      swap(arr[0],arr[i]);

      //heapify the array without the last element
      heapify(arr, i, 0);
   }
}
  
/* print contents of array */
void displayArray(vector<int> &arr, size_t n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{   
//    int n;
//    cout<<"size of array: ";
//    cin >> n;

   vector<int> heap_arr;
   
   cout << "Input array (enter -1 to end array input)"<<endl;
   while(true){
    int elmnt;
    cin >> elmnt;
    if (elmnt==-1) break;
    heap_arr.push_back(elmnt);
   }

//    int heap_arr[] = {4,17,3,12,9,6};
//    cout<<"Input array"<<endl;
//    displayArray(heap_arr,n);

   size_t n = heap_arr.size();
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
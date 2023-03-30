#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;


int partition(int* arr, int start, int end)
{  
      // assuming last element as pivotElement
    int index = 0, pivotElement = arr[end], pivotIndex;
    int* temp = new int[end - start + 1]; // making an array whose size is equal to current partition range...
    for (int i = start; i <= end; i++) // pushing all the elements in temp which are smaller than pivotElement
    {
        if(arr[i] < pivotElement)
        {
            temp[index] = arr[i];
            index++;
        }
    }
 
    temp[index] = pivotElement; // pushing pivotElement in temp
    index++;
 
    for (int i = start; i < end; i++) // pushing all the elements in temp which are greater than pivotElement
    {
        if(arr[i] > pivotElement)
        {
            temp[index] = arr[i];
            index++;
        }
    }
  // all the elements now in temp array are order :
  // leftmost elements are lesser than pivotElement and rightmost elements are greater than pivotElement
               
     
     
    index = 0;
    for (int i = start; i <= end; i++) // copying all the elements to original array i.e arr
    {  
        if(arr[i] == pivotElement)
        {
              // for getting pivot index in the original array.
              // we need the pivotIndex value in the original and not in the temp array
            pivotIndex = i;
        }
        arr[i] = temp[index];
        index++;
    }
    return pivotIndex; // returning pivotIndex
}
 
void recursiveQuickSort(int* arr, int start, int end)
{ 
    if(start < end)
    {  
        int partitionIndex = partition(arr, start, end); // for getting partition
        recursiveQuickSort(arr, start, partitionIndex - 1); // sorting left side array
        recursiveQuickSort(arr, partitionIndex + 1, end); // sorting right side array
    }
    return;
}

void IterativeQuickSort(int arr[], int l, int h)
{
    // Create an auxiliary stack
    int stack[h - l + 1];
  
    // initialize top of stack
    int top = -1;
  
    // push initial values of l and h to stack
    stack[++top] = l;
    stack[++top] = h;
  
    // Keep popping from stack while is not empty
    while (top >= 0) {
        // Pop h and l
        h = stack[top--];
        l = stack[top--];
  
        // Set pivot element at its correct position
        // in sorted array
        int p = partition(arr, l, h);
  
        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
  
        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}

int main()
{
    long long temp1 = 0, temp2 = 0;
    for (int i = 0; i < 10; i++){   
        const int sz=9000;
        int arr1[sz],arr2[sz];

        for(int i=0;i<sz;i++){
            int x = rand()%100;
            arr1[i] = x;
            arr2[i] = x;

        }

        //time taken by recursive quick sort
        auto start1 = high_resolution_clock::now();
        recursiveQuickSort(arr1, 0, sz - 1);
        auto stop1 = high_resolution_clock::now();
        auto duration1 = duration_cast<microseconds>(stop1-start1);
        temp1 += duration1.count();
        
        //time taken by iterative quick sort
        auto start2 = high_resolution_clock::now();
        IterativeQuickSort(arr2, 0, sz - 1);
        auto stop2 = high_resolution_clock::now();
        auto duration2 = duration_cast<microseconds>(stop2-start2);
        temp2 += duration2.count();
    }

    cout<<"Time for recursive quicksort: "<<temp1/10<< " microseconds "<<endl;
    cout<<"Time for iterative quicksort: "<<temp2/10<< " microseconds "<<endl;
    return 0;

}
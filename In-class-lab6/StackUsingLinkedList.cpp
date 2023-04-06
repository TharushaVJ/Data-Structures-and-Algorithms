#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Node {
    int data;

}

int main(){
    //initializing stack
    

    auto start = high_resolution_clock::now();

    //operations for the stack
    for (int i=0; i<10; i++){
        int n = rand() % 50;
        push(stack, n);
    }
    display(stack);
    for (int i=0; i<5; i++){
        pop(stack);
    }
    display(stack);
    for (int i=0; i<4; i++){
        int n = rand() % 50;
        push(stack, n);
    }
    display(stack);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout << "Time taken for the operations: " << duration.count() << " microseconds" <<endl;

    return 0;
}
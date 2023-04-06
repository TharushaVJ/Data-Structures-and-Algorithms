#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int top = -1;

void push(int stack[], int data, int x){;
    top++;
    if (top >= x) {
        cout << "Stack overflow" << endl;
        top--;
    }
    else stack[top] = data;
}

int pop(int stack[]){
    if (top == -1) cout << "Stack underflow" << endl;
    else{
        top--;
        return stack[top+1];
    }
}

void display(int stack[]){
    cout << "[ ";
    for (int i=0; i<=top; i++){
        cout << stack[i]<<" ";
    }
    cout << "]"<<endl;
}

int main(){
    //initializing stack
    cout << "Size of the stack (array): ";
    int x;
    cin >> x;
    int stack[x];

    auto start = high_resolution_clock::now();

    //operations for the stack
    for (int i=0; i<10; i++){
        int n = rand() % 50;
        push(stack, n, x);
        display(stack);
    }

    for (int i=0; i<5; i++){
        pop(stack);
        display(stack);
    }

    for (int i=0; i<4; i++){
        int n = rand() % 50;
        push(stack, n, x);
        display(stack);
    }


    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout << "Time taken for the operations: " << duration.count() << " microseconds" <<endl;

    return 0;
}
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int d) {
        data = d;
        next = NULL;
    }
};

// Stack class
class Stack {
public:
    Node* top;

    // Constructor
    Stack() {
        top = NULL;
    }

    // Push operation
    void push(int d) {
        Node* newNode = new Node(d);
        newNode->next = top;
        top = newNode;
        cout << d << endl;
    }

    // Pop operation
    void pop() {
        if (top == NULL) {
            cout << "Stack is empty." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << temp->data << endl;
        delete temp;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == NULL;
    }
};

    //display operation
    void display(Stack s) {
    if (s.isEmpty()) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "[ ";
    Node* curr = s.top;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout <<" ]"<< endl;
    }

int main(){
    //declaring stack
    Stack s;

    auto start = high_resolution_clock::now();

    //operations for the stack
    for (int i=0; i<10; i++){
        int n = rand() % 50;
        s.push(n);
        display(s);
    }

    for (int i=0; i<5; i++){
        s.pop();
        display(s);
    }

    for (int i=0; i<4; i++){
        int n = rand() % 50;
        s.push(n);
        display(s);
    }


    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout << "Time taken for the operations: " << duration.count() << " microseconds" <<endl;

    return 0;
}
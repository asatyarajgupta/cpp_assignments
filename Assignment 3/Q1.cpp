#include <iostream>
using namespace std;

// Global variables
int arr[100];
int top = -1;
int maxSize = 100;

void push(int x) {
    if (top == maxSize - 1) {
        cout << "Stack is full!" << endl;
        return;
    }
    arr[++top] = x;
    cout << "Pushed: " << x << endl;
}

void pop() {
    if (top == -1) {
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << "Popped: " << arr[top--] << endl;
}

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == maxSize - 1;
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << "Stack: ";
    for (int i = top; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void peek() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << "Top element: " << arr[top] << endl;
}

int main() {
    int choice, value;

    while (true) {
        cout << "\n--- Stack Menu ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Check if Empty" << endl;
        cout << "4. Check if Full" << endl;
        cout << "5. Display" << endl;
        cout << "6. Peek" << endl;
        cout << "7. Exit" << endl;
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                if (isEmpty()) {
                    cout << "Stack is empty" << endl;
                } else {
                    cout << "Stack is not empty" << endl;
                }
                break;
            case 4:
                if (isFull()) {
                    cout << "Stack is full" << endl;
                } else {
                    cout << "Stack is not full" << endl;
                }
                break;
            case 5:
                display();
                break;
            case 6:
                peek();
                break;
            case 7:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
#include <iostream>
#include <queue>
using namespace std;

// Stack using Two Queues
class StackUsingTwoQueues {
private:
    queue<int> q1, q2;

public:
    void push(int data) {
        q2.push(data);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Popped: " << q1.front() << endl;
        q1.pop();
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }

    void display() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        queue<int> temp = q1;
        cout << "Stack: ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

// Stack using One Queue
class StackUsingOneQueue {
private:
    queue<int> q;

public:
    void push(int data) {
        q.push(data);
        int size = q.size();
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Popped: " << q.front() << endl;
        q.pop();
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q.front();
    }

    bool empty() {
        return q.empty();
    }

    void display() {
        if (q.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        queue<int> temp = q;
        cout << "Stack: ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    int choice, implementation, data;
    
    cout << "Choose implementation:" << endl;
    cout << "1. Stack using Two Queues" << endl;
    cout << "2. Stack using One Queue" << endl;
    cout << "Enter choice (1 or 2): ";
    cin >> implementation;

    if (implementation == 1) {
        StackUsingTwoQueues stack;
        
        while (true) {
            cout << "\n=== Stack using Two Queues ===" << endl;
            cout << "1. Push" << endl;
            cout << "2. Pop" << endl;
            cout << "3. Top" << endl;
            cout << "4. Is Empty?" << endl;
            cout << "5. Display" << endl;
            cout << "6. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter data to push: ";
                    cin >> data;
                    stack.push(data);
                    break;
                case 2:
                    stack.pop();
                    break;
                case 3:
                    if (!stack.empty()) {
                        cout << "Top element: " << stack.top() << endl;
                    }
                    break;
                case 4:
                    if (stack.empty()) {
                        cout << "Yes, stack is empty!" << endl;
                    } else {
                        cout << "No, stack is not empty!" << endl;
                    }
                    break;
                case 5:
                    stack.display();
                    break;
                case 6:
                    cout << "Exiting program..." << endl;
                    return 0;
                default:
                    cout << "Invalid choice! Please try again." << endl;
            }
        }
    } else if (implementation == 2) {
        StackUsingOneQueue stack;
        
        while (true) {
            cout << "\n=== Stack using One Queue ===" << endl;
            cout << "1. Push" << endl;
            cout << "2. Pop" << endl;
            cout << "3. Top" << endl;
            cout << "4. Is Empty?" << endl;
            cout << "5. Display" << endl;
            cout << "6. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter data to push: ";
                    cin >> data;
                    stack.push(data);
                    break;
                case 2:
                    stack.pop();
                    break;
                case 3:
                    if (!stack.empty()) {
                        cout << "Top element: " << stack.top() << endl;
                    }
                    break;
                case 4:
                    if (stack.empty()) {
                        cout << "Yes, stack is empty!" << endl;
                    } else {
                        cout << "No, stack is not empty!" << endl;
                    }
                    break;
                case 5:
                    stack.display();
                    break;
                case 6:
                    cout << "Exiting program..." << endl;
                    return 0;
                default:
                    cout << "Invalid choice! Please try again." << endl;
            }
        }
    } else {
        cout << "Invalid implementation choice!" << endl;
    }
    
    return 0;
}

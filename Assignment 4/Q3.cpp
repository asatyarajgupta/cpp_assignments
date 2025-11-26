#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue size must be even for interleaving!" << endl;
        return;
    }
    
    queue<int> temp;
    
    // Move first half to temp queue
    for (int i = 0; i < n/2; i++) {
        temp.push(q.front());
        q.pop();
    }
    
    // Interleave elements
    while (!temp.empty()) {
        q.push(temp.front());
        temp.pop();
        q.push(q.front());
        q.pop();
    }
}

void displayQueue(queue<int> q) {
    cout << "Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    int n, element;
    
    cout << "Enter the number of elements (must be even): ";
    cin >> n;
    
    if (n % 2 != 0) {
        cout << "Number of elements must be even for interleaving!" << endl;
        return 0;
    }
    
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> element;
        q.push(element);
    }
    
    cout << "\nOriginal queue: ";
    displayQueue(q);
    
    interleaveQueue(q);
    
    cout << "Interleaved queue: ";
    displayQueue(q);
    
    return 0;
}

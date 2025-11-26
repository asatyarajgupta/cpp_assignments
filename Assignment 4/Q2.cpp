#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *arr;
    int front;
    int rear;
    int capacity;
    int size;

public:
    CircularQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue " << data << endl;
            return;
        }
        
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = data;
        size++;
        cout << "Enqueued " << data << " successfully!" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }
        
        int data = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        size--;
        cout << "Dequeued " << data << " successfully!" << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty! Nothing to peek." << endl;
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        
        cout << "Queue elements: ";
        int i = front;
        int count = 0;
        while (count < size) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
            count++;
        }
        cout << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the circular queue: ";
    cin >> capacity;
    
    CircularQueue queue(capacity);
    int choice, data;

    while (true) {
        cout << "\n=== Circular Queue Operations ===" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Is Empty?" << endl;
        cout << "4. Is Full?" << endl;
        cout << "5. Display" << endl;
        cout << "6. Peek" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to enqueue: ";
                cin >> data;
                queue.enqueue(data);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                if (queue.isEmpty()) {
                    cout << "Yes, queue is empty!" << endl;
                } else {
                    cout << "No, queue is not empty!" << endl;
                }
                break;
            case 4:
                if (queue.isFull()) {
                    cout << "Yes, queue is full!" << endl;
                } else {
                    cout << "No, queue is not full!" << endl;
                }
                break;
            case 5:
                queue.display();
                break;
            case 6:
                queue.peek();
                break;
            case 7:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}

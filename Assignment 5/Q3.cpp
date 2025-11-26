#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    
public:
    LinkedList() {
        head = nullptr;
    }
    
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        
        cout << "Linked List: ";
        Node* current = head;
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << " -> NULL" << endl;
    }
    
    int findMiddle() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return -1;
        }
        
        Node* slow = head;
        Node* fast = head;
        
        // Move fast pointer by 2 steps and slow pointer by 1 step
        // When fast reaches the end, slow will be at the middle
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow->data;
    }
    
    void createFromArray(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            insertAtEnd(arr[i]);
        }
    }
};

int main() {
    LinkedList list;
    int n;
    
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int* arr = new int[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Create linked list from array
    list.createFromArray(arr, n);
    
    cout << "\nOriginal linked list:" << endl;
    list.display();
    
    // Find and display middle element
    int middle = list.findMiddle();
    if (middle != -1) {
        cout << "\nMiddle element: " << middle << endl;
    }
    
    delete[] arr;
    return 0;
}

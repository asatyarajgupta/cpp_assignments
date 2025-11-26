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
    
    void reverse() {
        if (head == nullptr || head->next == nullptr) {
            cout << "List is empty or has only one element. No need to reverse." << endl;
            return;
        }
        
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        
        while (current != nullptr) {
            next = current->next;  // Store next node
            current->next = prev;  // Reverse current node's pointer
            prev = current;        // Move prev to current
            current = next;        // Move current to next
        }
        
        head = prev;  // Update head to point to the new first node
        cout << "Linked list has been reversed successfully!" << endl;
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
    
    // Reverse the linked list
    list.reverse();
    
    cout << "\nReversed linked list:" << endl;
    list.display();
    
    delete[] arr;
    return 0;
}

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
    
    int countOccurrences(int key) {
        int count = 0;
        Node* current = head;
        
        while (current != nullptr) {
            if (current->data == key) {
                count++;
            }
            current = current->next;
        }
        
        return count;
    }
    
    void deleteAllOccurrences(int key) {
        // Delete all occurrences from the beginning
        while (head != nullptr && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        
        // Delete occurrences from the rest of the list
        if (head != nullptr) {
            Node* current = head;
            while (current->next != nullptr) {
                if (current->next->data == key) {
                    Node* temp = current->next;
                    current->next = current->next->next;
                    delete temp;
                } else {
                    current = current->next;
                }
            }
        }
    }
    
    void createFromArray(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            insertAtEnd(arr[i]);
        }
    }
};

int main() {
    LinkedList list;
    int n, key;
    
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
    
    cout << "\nEnter the key to count and delete: ";
    cin >> key;
    
    // Count occurrences
    int count = list.countOccurrences(key);
    cout << "\nNumber of occurrences of " << key << ": " << count << endl;
    
    // Delete all occurrences
    list.deleteAllOccurrences(key);
    
    cout << "\nLinked list after deleting all occurrences of " << key << ":" << endl;
    list.display();
    
    delete[] arr;
    return 0;
}

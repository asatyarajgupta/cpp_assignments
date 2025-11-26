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

class SinglyLinkedList {
private:
    Node* head;
    
public:
    SinglyLinkedList() {
        head = nullptr;
    }
    
    ~SinglyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    
    // (a) Insertion at the beginning
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << data << " at the beginning." << endl;
    }
    
    // (b) Insertion at the end
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
        cout << "Inserted " << data << " at the end." << endl;
    }
    
    // (c) Insertion before a specific value
    void insertBefore(int data, int targetValue) {
        if (head == nullptr) {
            cout << "List is empty. Cannot insert before " << targetValue << endl;
            return;
        }
        
        if (head->data == targetValue) {
            insertAtBeginning(data);
            return;
        }
        
        Node* current = head;
        while (current->next != nullptr && current->next->data != targetValue) {
            current = current->next;
        }
        
        if (current->next == nullptr) {
            cout << "Value " << targetValue << " not found in the list." << endl;
            return;
        }
        
        Node* newNode = new Node(data);
        newNode->next = current->next;
        current->next = newNode;
        cout << "Inserted " << data << " before " << targetValue << "." << endl;
    }
    
    // (c) Insertion after a specific value
    void insertAfter(int data, int targetValue) {
        if (head == nullptr) {
            cout << "List is empty. Cannot insert after " << targetValue << endl;
            return;
        }
        
        Node* current = head;
        while (current != nullptr && current->data != targetValue) {
            current = current->next;
        }
        
        if (current == nullptr) {
            cout << "Value " << targetValue << " not found in the list." << endl;
            return;
        }
        
        Node* newNode = new Node(data);
        newNode->next = current->next;
        current->next = newNode;
        cout << "Inserted " << data << " after " << targetValue << "." << endl;
    }
    
    // (d) Deletion from the beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete from beginning." << endl;
            return;
        }
        
        Node* temp = head;
        head = head->next;
        cout << "Deleted " << temp->data << " from the beginning." << endl;
        delete temp;
    }
    
    // (e) Deletion from the end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete from end." << endl;
            return;
        }
        
        if (head->next == nullptr) {
            cout << "Deleted " << head->data << " from the end." << endl;
            delete head;
            head = nullptr;
            return;
        }
        
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        
        cout << "Deleted " << current->next->data << " from the end." << endl;
        delete current->next;
        current->next = nullptr;
    }
    
    // (f) Deletion of a specific node
    void deleteSpecificNode(int targetValue) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete " << targetValue << endl;
            return;
        }
        
        if (head->data == targetValue) {
            deleteFromBeginning();
            return;
        }
        
        Node* current = head;
        while (current->next != nullptr && current->next->data != targetValue) {
            current = current->next;
        }
        
        if (current->next == nullptr) {
            cout << "Value " << targetValue << " not found in the list." << endl;
            return;
        }
        
        Node* temp = current->next;
        current->next = current->next->next;
        cout << "Deleted " << temp->data << " from the list." << endl;
        delete temp;
    }
    
    // (g) Search for a node and display its position
    void searchNode(int targetValue) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        
        Node* current = head;
        int position = 1;
        
        while (current != nullptr) {
            if (current->data == targetValue) {
                cout << "Value " << targetValue << " found at position " << position << " from head." << endl;
                return;
            }
            current = current->next;
            position++;
        }
        
        cout << "Value " << targetValue << " not found in the list." << endl;
    }
    
    // (h) Display all node values
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
};

int main() {
    SinglyLinkedList list;
    int choice, data, targetValue;
    
    while (true) {
        cout << "\n=== Singly Linked List Operations ===" << endl;
        cout << "1. Insert at beginning" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Insert before a value" << endl;
        cout << "4. Insert after a value" << endl;
        cout << "5. Delete from beginning" << endl;
        cout << "6. Delete from end" << endl;
        cout << "7. Delete specific node" << endl;
        cout << "8. Search for a node" << endl;
        cout << "9. Display all nodes" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter data to insert at beginning: ";
                cin >> data;
                list.insertAtBeginning(data);
                break;
            case 2:
                cout << "Enter data to insert at end: ";
                cin >> data;
                list.insertAtEnd(data);
                break;
            case 3:
                cout << "Enter data to insert: ";
                cin >> data;
                cout << "Enter value before which to insert: ";
                cin >> targetValue;
                list.insertBefore(data, targetValue);
                break;
            case 4:
                cout << "Enter data to insert: ";
                cin >> data;
                cout << "Enter value after which to insert: ";
                cin >> targetValue;
                list.insertAfter(data, targetValue);
                break;
            case 5:
                list.deleteFromBeginning();
                break;
            case 6:
                list.deleteFromEnd();
                break;
            case 7:
                cout << "Enter value to delete: ";
                cin >> targetValue;
                list.deleteSpecificNode(targetValue);
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> targetValue;
                list.searchNode(targetValue);
                break;
            case 9:
                list.display();
                break;
            case 10:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    
    return 0;
}

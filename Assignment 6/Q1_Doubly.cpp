#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
  Node *prev;
  Node(int val) {
    data = val;
    next = NULL;
    prev = NULL;
  }
};

class DoublyLinkedList {
  Node *head;

public:
  DoublyLinkedList() { head = NULL; }

  void insertBegin(int val) {
    Node *newNode = new Node(val);
    if (!head) {
      head = newNode;
    } else {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
  }

  void insertEnd(int val) {
    Node *newNode = new Node(val);
    if (!head) {
      head = newNode;
      return;
    }
    Node *temp = head;
    while (temp->next)
      temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
  }

  void insertAfter(int key, int val) {
    Node *temp = head;
    while (temp) {
      if (temp->data == key) {
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
          temp->next->prev = newNode;
        temp->next = newNode;
        return;
      }
      temp = temp->next;
    }
    cout << "Node not found" << endl;
  }

  void deleteNode(int key) {
    if (!head)
      return;

    if (head->data == key) {
      Node *temp = head;
      head = head->next;
      if (head)
        head->prev = NULL;
      delete temp;
      return;
    }

    Node *temp = head;
    while (temp) {
      if (temp->data == key) {
        if (temp->next)
          temp->next->prev = temp->prev;
        if (temp->prev)
          temp->prev->next = temp->next;
        delete temp;
        return;
      }
      temp = temp->next;
    }
  }

  void search(int key) {
    Node *temp = head;
    int pos = 1;
    while (temp) {
      if (temp->data == key) {
        cout << "Found at position " << pos << endl;
        return;
      }
      temp = temp->next;
      pos++;
    }
    cout << "Not found" << endl;
  }

  void display() {
    Node *temp = head;
    while (temp) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

int main() {
  DoublyLinkedList dll;
  int choice, val, key;
  while (true) {
    cout << "\n1. Insert Begin\n2. Insert End\n3. Insert After\n4. Delete\n5. "
            "Search\n6. Display\n7. Exit\nEnter choice: ";
    cin >> choice;
    if (choice == 7)
      break;
    switch (choice) {
    case 1:
      cout << "Val: ";
      cin >> val;
      dll.insertBegin(val);
      break;
    case 2:
      cout << "Val: ";
      cin >> val;
      dll.insertEnd(val);
      break;
    case 3:
      cout << "Key: ";
      cin >> key;
      cout << "Val: ";
      cin >> val;
      dll.insertAfter(key, val);
      break;
    case 4:
      cout << "Val: ";
      cin >> val;
      dll.deleteNode(val);
      break;
    case 5:
      cout << "Val: ";
      cin >> val;
      dll.search(val);
      break;
    case 6:
      dll.display();
      break;
    }
  }
  return 0;
}

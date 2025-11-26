#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
  Node(int val) {
    data = val;
    next = NULL;
  }
};

class CircularLinkedList {
  Node *head;

public:
  CircularLinkedList() { head = NULL; }

  void insertBegin(int val) {
    Node *newNode = new Node(val);
    if (!head) {
      head = newNode;
      newNode->next = head;
    } else {
      Node *temp = head;
      while (temp->next != head)
        temp = temp->next;
      temp->next = newNode;
      newNode->next = head;
      head = newNode;
    }
  }

  void insertEnd(int val) {
    Node *newNode = new Node(val);
    if (!head) {
      head = newNode;
      newNode->next = head;
    } else {
      Node *temp = head;
      while (temp->next != head)
        temp = temp->next;
      temp->next = newNode;
      newNode->next = head;
    }
  }

  void insertAfter(int key, int val) {
    if (!head)
      return;
    Node *temp = head;
    do {
      if (temp->data == key) {
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        return;
      }
      temp = temp->next;
    } while (temp != head);
  }

  void deleteNode(int key) {
    if (!head)
      return;
    if (head->data == key && head->next == head) {
      delete head;
      head = NULL;
      return;
    }

    Node *curr = head;
    Node *prev = NULL;

    if (head->data == key) {
      while (curr->next != head)
        curr = curr->next;
      curr->next = head->next;
      delete head;
      head = curr->next;
      return;
    }

    do {
      if (curr->data == key) {
        prev->next = curr->next;
        delete curr;
        return;
      }
      prev = curr;
      curr = curr->next;
    } while (curr != head);
  }

  void search(int key) {
    if (!head) {
      cout << "List is empty" << endl;
      return;
    }
    Node *temp = head;
    int pos = 1;
    do {
      if (temp->data == key) {
        cout << "Found at position " << pos << endl;
        return;
      }
      temp = temp->next;
      pos++;
    } while (temp != head);
    cout << "Not found" << endl;
  }

  void display() {
    if (!head)
      return;
    Node *temp = head;
    do {
      cout << temp->data << " ";
      temp = temp->next;
    } while (temp != head);
    cout << endl;
  }
};

int main() {
  CircularLinkedList cll;
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
      cll.insertBegin(val);
      break;
    case 2:
      cout << "Val: ";
      cin >> val;
      cll.insertEnd(val);
      break;
    case 3:
      cout << "Key: ";
      cin >> key;
      cout << "Val: ";
      cin >> val;
      cll.insertAfter(key, val);
      break;
    case 4:
      cout << "Val: ";
      cin >> val;
      cll.deleteNode(val);
      break;
    case 5:
      cout << "Val: ";
      cin >> val;
      cll.search(val);
      break;
    case 6:
      cll.display();
      break;
    }
  }
  return 0;
}

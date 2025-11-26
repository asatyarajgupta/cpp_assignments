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

void insert(Node *&head, int val) {
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

void display(Node *head) {
  if (!head)
    return;
  Node *temp = head;
  do {
    cout << temp->data << " ";
    temp = temp->next;
  } while (temp != head);
  cout << head->data << endl; // Repeat head at the end
}

int main() {
  Node *head = NULL;
  insert(head, 20);
  insert(head, 100);
  insert(head, 40);
  insert(head, 80);
  insert(head, 60);

  cout << "Output: ";
  display(head);

  return 0;
}

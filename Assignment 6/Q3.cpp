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

int sizeDoubly(Node *head) {
  int count = 0;
  while (head) {
    count++;
    head = head->next;
  }
  return count;
}

int sizeCircular(Node *head) {
  if (!head)
    return 0;
  int count = 0;
  Node *temp = head;
  do {
    count++;
    temp = temp->next;
  } while (temp != head);
  return count;
}

int main() {
  // Doubly Linked List
  Node *dHead = new Node(1);
  dHead->next = new Node(2);
  dHead->next->prev = dHead;
  dHead->next->next = new Node(3);
  dHead->next->next->prev = dHead->next;

  cout << "Size of Doubly Linked List: " << sizeDoubly(dHead) << endl;

  // Circular Linked List
  Node *cHead = new Node(10);
  cHead->next = new Node(20);
  cHead->next->next = new Node(30);
  cHead->next->next->next = cHead;

  cout << "Size of Circular Linked List: " << sizeCircular(cHead) << endl;

  return 0;
}

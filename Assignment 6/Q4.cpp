#include <iostream>
using namespace std;

struct Node {
  char data;
  Node *next;
  Node *prev;
  Node(char val) {
    data = val;
    next = NULL;
    prev = NULL;
  }
};

void insert(Node *&head, char val) {
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

bool isPalindrome(Node *head) {
  if (!head)
    return true;
  Node *tail = head;
  while (tail->next)
    tail = tail->next;

  while (head != tail && head->prev != tail) {
    if (head->data != tail->data)
      return false;
    head = head->next;
    tail = tail->prev;
  }
  return true;
}

int main() {
  Node *head = NULL;
  insert(head, 'R');
  insert(head, 'A');
  insert(head, 'D');
  insert(head, 'A');
  insert(head, 'R');

  if (isPalindrome(head))
    cout << "Is Palindrome" << endl;
  else
    cout << "Not Palindrome" << endl;

  Node *head2 = NULL;
  insert(head2, 'H');
  insert(head2, 'E');
  insert(head2, 'L');
  insert(head2, 'L');
  insert(head2, 'O');

  if (isPalindrome(head2))
    cout << "Is Palindrome" << endl;
  else
    cout << "Not Palindrome" << endl;

  return 0;
}

#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    data = val;
    left = NULL;
    right = NULL;
  }
};

Node *insert(Node *root, int val) {
  if (root == NULL)
    return new Node(val);
  if (val < root->data)
    root->left = insert(root->left, val);
  else
    root->right = insert(root->right, val);
  return root;
}

bool searchRecursive(Node *root, int key) {
  if (root == NULL)
    return false;
  if (root->data == key)
    return true;
  if (key < root->data)
    return searchRecursive(root->left, key);
  return searchRecursive(root->right, key);
}

bool searchIterative(Node *root, int key) {
  while (root != NULL) {
    if (root->data == key)
      return true;
    if (key < root->data)
      root = root->left;
    else
      root = root->right;
  }
  return false;
}

int findMax(Node *root) {
  if (root == NULL)
    return -1;
  while (root->right != NULL)
    root = root->right;
  return root->data;
}

int findMin(Node *root) {
  if (root == NULL)
    return -1;
  while (root->left != NULL)
    root = root->left;
  return root->data;
}

Node *findMinNode(Node *root) {
  while (root->left != NULL)
    root = root->left;
  return root;
}

Node *findMaxNode(Node *root) {
  while (root->right != NULL)
    root = root->right;
  return root;
}

Node *findSuccessor(Node *root, int key) {
  Node *current = root;
  Node *successor = NULL;

  // First find the node
  Node *target = NULL;
  while (current != NULL) {
    if (current->data == key) {
      target = current;
      break;
    } else if (key < current->data) {
      successor = current;
      current = current->left;
    } else {
      current = current->right;
    }
  }

  if (target == NULL)
    return NULL;

  if (target->right != NULL) {
    return findMinNode(target->right);
  }

  return successor;
}

Node *findPredecessor(Node *root, int key) {
  Node *current = root;
  Node *predecessor = NULL;

  Node *target = NULL;
  while (current != NULL) {
    if (current->data == key) {
      target = current;
      break;
    } else if (key < current->data) {
      current = current->left;
    } else {
      predecessor = current;
      current = current->right;
    }
  }

  if (target == NULL)
    return NULL;

  if (target->left != NULL) {
    return findMaxNode(target->left);
  }

  return predecessor;
}

int main() {
  Node *root = NULL;
  int values[] = {50, 30, 20, 40, 70, 60, 80};
  for (int i = 0; i < 7; i++)
    root = insert(root, values[i]);

  cout << "Search 40 (Recursive): "
       << (searchRecursive(root, 40) ? "Found" : "Not Found") << endl;
  cout << "Search 90 (Iterative): "
       << (searchIterative(root, 90) ? "Found" : "Not Found") << endl;

  cout << "Max element: " << findMax(root) << endl;
  cout << "Min element: " << findMin(root) << endl;

  Node *succ = findSuccessor(root, 40);
  if (succ)
    cout << "Successor of 40: " << succ->data << endl;
  else
    cout << "Successor of 40: None" << endl;

  Node *pred = findPredecessor(root, 40);
  if (pred)
    cout << "Predecessor of 40: " << pred->data << endl;
  else
    cout << "Predecessor of 40: None" << endl;

  return 0;
}

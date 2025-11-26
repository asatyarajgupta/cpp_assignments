#include <algorithm>
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
  if (val == root->data)
    return root; // No duplicates
  if (val < root->data)
    root->left = insert(root->left, val);
  else
    root->right = insert(root->right, val);
  return root;
}

Node *findMin(Node *root) {
  while (root->left != NULL)
    root = root->left;
  return root;
}

Node *deleteNode(Node *root, int key) {
  if (root == NULL)
    return root;

  if (key < root->data)
    root->left = deleteNode(root->left, key);
  else if (key > root->data)
    root->right = deleteNode(root->right, key);
  else {
    if (root->left == NULL) {
      Node *temp = root->right;
      delete root;
      return temp;
    } else if (root->right == NULL) {
      Node *temp = root->left;
      delete root;
      return temp;
    }
    Node *temp = findMin(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}

int maxDepth(Node *root) {
  if (root == NULL)
    return 0;
  return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node *root) {
  if (root == NULL)
    return 0;
  if (root->left == NULL && root->right == NULL)
    return 1;
  if (root->left == NULL)
    return 1 + minDepth(root->right);
  if (root->right == NULL)
    return 1 + minDepth(root->left);
  return 1 + min(minDepth(root->left), minDepth(root->right));
}

void inorder(Node *root) {
  if (root == NULL)
    return;
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

int main() {
  Node *root = NULL;
  root = insert(root, 50);
  root = insert(root, 30);
  root = insert(root, 20);
  root = insert(root, 40);
  root = insert(root, 70);
  root = insert(root, 60);
  root = insert(root, 80);
  root = insert(root, 50); // Duplicate

  cout << "Inorder after insertion: ";
  inorder(root);
  cout << endl;

  cout << "Max Depth: " << maxDepth(root) << endl;
  cout << "Min Depth: " << minDepth(root) << endl;

  root = deleteNode(root, 20);
  cout << "Inorder after deleting 20: ";
  inorder(root);
  cout << endl;

  root = deleteNode(root, 30);
  cout << "Inorder after deleting 30: ";
  inorder(root);
  cout << endl;

  root = deleteNode(root, 50);
  cout << "Inorder after deleting 50: ";
  inorder(root);
  cout << endl;

  return 0;
}

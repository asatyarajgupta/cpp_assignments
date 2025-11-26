#include <climits>
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

bool isBSTUtil(Node *node, int min, int max) {
  if (node == NULL)
    return true;
  if (node->data < min || node->data > max)
    return false;
  return isBSTUtil(node->left, min, node->data - 1) &&
         isBSTUtil(node->right, node->data + 1, max);
}

bool isBST(Node *root) { return isBSTUtil(root, INT_MIN, INT_MAX); }

int main() {
  Node *root = new Node(4);
  root->left = new Node(2);
  root->right = new Node(5);
  root->left->left = new Node(1);
  root->left->right = new Node(3);

  if (isBST(root))
    cout << "Is BST" << endl;
  else
    cout << "Not a BST" << endl;

  root->left->right->data = 100; // Make it invalid

  if (isBST(root))
    cout << "Is BST" << endl;
  else
    cout << "Not a BST" << endl;

  return 0;
}

#include <iostream>
using namespace std;

class PriorityQueue {
private:
  int heap[100];
  int size;

  void heapifyUp(int i) {
    while (i > 0) {
      int parent = (i - 1) / 2;
      if (heap[parent] < heap[i]) {
        swap(heap[parent], heap[i]);
        i = parent;
      } else {
        break;
      }
    }
  }

  void heapifyDown(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] > heap[largest])
      largest = left;
    if (right < size && heap[right] > heap[largest])
      largest = right;

    if (largest != i) {
      swap(heap[i], heap[largest]);
      heapifyDown(largest);
    }
  }

public:
  PriorityQueue() { size = 0; }

  void push(int val) {
    if (size >= 100) {
      cout << "Queue Overflow" << endl;
      return;
    }
    heap[size] = val;
    heapifyUp(size);
    size++;
  }

  void pop() {
    if (size <= 0) {
      cout << "Priority Queue is empty" << endl;
      return;
    }
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
  }

  int top() {
    if (size <= 0) {
      cout << "Priority Queue is empty" << endl;
      return -1;
    }
    return heap[0];
  }

  bool empty() { return size == 0; }
};

int main() {
  PriorityQueue pq;
  pq.push(10);
  pq.push(30);
  pq.push(20);
  pq.push(5);
  pq.push(1);

  cout << "Top element: " << pq.top() << endl;

  pq.pop();
  cout << "Top element after pop: " << pq.top() << endl;

  pq.pop();
  cout << "Top element after pop: " << pq.top() << endl;

  return 0;
}

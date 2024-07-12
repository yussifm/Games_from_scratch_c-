#include <iostream>
#include <memory>

using namespace std;

struct Node {
  int data;
  Node *next;
};

int main() {

  // Using Smart pointers
  unique_ptr<Node> p;
  p = make_unique<Node>();

  p->data = 10;
  p->next = NULL;

  cout << p->data << endl;
  cout << p->next << endl;

  // Using Raw Pointers
  Node *q;
  q = new Node;
  q->data = 20;
  q->next = NULL;

  cout << q->data << endl;
  cout << q->next << endl;

  // connection
  unique_ptr<Node> R;
  R = make_unique<Node>();
  R->next = q;

  cout << R->next->data << endl;

  delete q;
  return 0;
}

#include <iostream>
#include <memory>

using namespace std;

struct Node {
  int data;
  Node *next;
};

class SinglyLinkedList {

private:
  unique_ptr<Node> head;
  unique_ptr<Node> tail;
public:
  SinglyLinkedList() {
    head = nullptr;
    tail = nullptr;
  }
  void create(int data) {
  
  }
};

int main() { return 0; }
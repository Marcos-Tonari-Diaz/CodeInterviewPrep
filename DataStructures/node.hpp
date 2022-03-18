#ifndef NODE
#define NODE

#include <memory>

using namespace std;

class Node {
  shared_ptr<Node> next;
  int data;

 public:
  Node(int data) : data{data}, next{nullptr} {};
  int getData() { return data; }
  shared_ptr<Node>& getNext() { return next; }
  void setNext(shared_ptr<Node>& node) { next = move(node); }
};

#endif
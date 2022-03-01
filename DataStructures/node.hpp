#include <memory>

using namespace std;

class Node {
  unique_ptr<Node> next;
  int data;

 public:
  Node(int data) : data{data}, next{nullptr} {};
  int getData() { return data; }
  unique_ptr<Node>& getNext() { return next; }
  void setNext(unique_ptr<Node>& node) { next = move(node); }
};
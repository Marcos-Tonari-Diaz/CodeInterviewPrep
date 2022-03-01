#include <iostream>
#include <memory>

#include "../node.hpp"

using namespace std;

class BinaryTree {
  unique_ptr<Node> left;
  unique_ptr<Node> right;

 public:
  unique_ptr<Node>& getLeft() { return left; };
  unique_ptr<Node>& getRight() { return right; };
};

int main() {
  BinaryTree tree;
  if (tree.getLeft().get() == nullptr) cout << "null" << endl;
  return 0;
}

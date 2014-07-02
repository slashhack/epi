#ifndef SRC_CH10_NODE_HPP
#define SRC_CH10_NODE_HPP

#include <memory>

template <typename T>
struct BinaryTreeNode {
  T data;
  std::unique_ptr<BinaryTreeNode<T>> left, right;

};

#endif

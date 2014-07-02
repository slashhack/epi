#ifndef SRC_CH08_LIST_HPP
#define SRC_CH08_LIST_HPP

#include <memory>

template <typename T>
struct ListNode {
  T data;
  std::shared_ptr<ListNode<T>> next;

  ListNode<T>() : data(0) {
  }
};

#endif

#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"


#include <algorithm>

#include <stack>

using namespace std;

template<typename T>
class Stack1 {
 public:
  Stack1<T>(void) :
      stack_(),
      aux_() {
    
  }

  ~Stack1<T>(void) {
    stack_.clear();
    aux_.clear();
  }

  void push(T t) {
    if(stack_.empty()) {
      aux_.push();
    } else {
      aux_.push(max(aux_.top(), t));
    }
    stack_.push(t);
  }

  T pop(void) {
    // no reason throw exception in this point
    // see http://www.sgi.com/tech/stl/stack.html#3
    // suitable prototype should be void pop and have another function
    // T top
    T t;

    t = stack_.pop();
    aux_.pop();

    return t;
  }


  bool empty(void) const {
    return stack_.empty();
  }

  typename stack<T>::size_type size(void) const {
    return stack_.size();
  }

 private:
  stack<T> stack_;
  stack<T> aux_;
};



int main(int argc, char **argv) {

  return 0;
}

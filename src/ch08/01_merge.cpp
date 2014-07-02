#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include "list.hpp"



template <typename T>
int merge1(ListNode<T> L, ListNode<T> F, ListNode<T> &M) {
  int err = 0;

  ListNode<T> * l = &(L->next);
  ListNode<T> * f = &(F->next);

  ListNode<T> * m = M;

  while(true) {
    if(l->data < f->data) {
      m->next = l;
      l = l->next;
    } else {
      m->next = f;
      f = f->next;
    }
    m = m->next;

    if((NULL == l) || (NULL == f)) {
      break;
    }
  }

  while(NULL != l) {
    m->next = l;
    
    l = l->next;
    m = m->next;
  }

  while(NULL != f) {
    m->next = f;

    f = f->next;
    m = m->next;
  }

  m->next = NULL;
                       
  
  return err;
}

int main(int argc, char **argv) {
  
  ListNode<int> L;
  L->next = allocate_shared<ListNode<int>>();
  
  L->next->data = 2;
  
  return 0;
}

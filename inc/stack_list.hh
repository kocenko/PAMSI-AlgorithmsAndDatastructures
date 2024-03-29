#ifndef STACK_LIST_HH
#define STACK_LIST_HH

#include "singly_linked_list.hh"

template <typename T>
class StackLinkedList{
private:
    SinglyLinkedList<T> data;
public:
    StackLinkedList() = default;

    void push(T element);
    T pop();
    T peek();
    bool is_empty();
};


#endif  // STACK_LIST_HH
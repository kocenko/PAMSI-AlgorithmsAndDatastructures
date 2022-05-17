#include <iostream>
#include <stdexcept>

#include "stack_list.hh"
#include "singly_linked_list.hh"
#include "singly_linked_list_node.hh"


template <typename T>
void StackLinkedList<T>::push(T element){
    data.add_node_at_beginning(element);
}

template <typename T>
T StackLinkedList<T>::pop(){
    SinglyLinkedListNode<T>* node;
    T to_return = 0;
    if (is_empty()){
        std::cerr << "Empty stack" << std::endl;
    }
    else{
        node = data.remove_node_from_beginning();
        to_return = node->get_value();
        delete node;
    }
    return to_return;
}

template <typename T>
T StackLinkedList<T>::peek(){
    if (is_empty()){
        throw std::range_error("Cannot peek to the top of an empty stack");
    }
    return data.peek_beginning();
}

template <typename T>
bool StackLinkedList<T>::is_empty(){
    return data.is_empty();
}

template class StackLinkedList<int>;
template class StackLinkedList<double>;
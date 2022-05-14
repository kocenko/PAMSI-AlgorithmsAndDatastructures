#include "singly_linked_list_node.hh"

template <typename T>
SinglyLinkedListNode<T>::SinglyLinkedListNode(SinglyLinkedListNode<T>* p_next, T p_value){
    next = p_next;
    value = p_value;
}

template <typename T>
void SinglyLinkedListNode<T>::set_next(SinglyLinkedListNode<T>* p_next){
    next = p_next;
}

template <typename T>
SinglyLinkedListNode<T>* SinglyLinkedListNode<T>::get_next(){
    return next;
}

template class SinglyLinkedListNode<int>;
template class SinglyLinkedListNode<double>;
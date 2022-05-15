#include <iostream>

#include "singly_linked_list.hh"
#include "singly_linked_list_node.hh"


template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(){
    head = nullptr;
}

template <typename T>
void SinglyLinkedList<T>::add_node_at_beginning(T value){
    SinglyLinkedListNode<T>* new_node = new SinglyLinkedListNode<T>(head, value);
    set_head(new_node);
}

template <typename T>
void SinglyLinkedList<T>::add_node_at_end(T value){
    SinglyLinkedListNode<T>* temp;
    SinglyLinkedListNode<T>* new_node = new SinglyLinkedListNode<T>(nullptr, value);
    if(head == nullptr){
        set_head(new_node);
    }
    else{
        temp = get_head();
        while(temp->get_next() != nullptr){
            temp = temp->get_next();
        }
        temp->set_next(new_node);
    }
}

template <typename T>
SinglyLinkedListNode<T>* SinglyLinkedList<T>::remove_node_from_beginning(){
    SinglyLinkedListNode<T>* temp = nullptr;
    if(head == nullptr){
        std::cerr << "Cannot remove node from the beginning of the linked list because it is empty" << std::endl;
    }
    else{
        temp = get_head();
        set_head(head->get_next());
        temp->set_next(nullptr);
    }
    return temp;
}

template <typename T>
SinglyLinkedListNode<T>* SinglyLinkedList<T>::remove_node_from_end(){
    SinglyLinkedListNode<T>* temp = nullptr;
    SinglyLinkedListNode<T>* to_return = nullptr;
    if(head == nullptr){
        std::cerr << "Cannot remove node from the end of the linked list because it is empty" << std::endl;
    }
    else{
        temp = get_head();
        to_return = temp;
        while (to_return->get_next() != nullptr){
            temp = to_return;
            to_return = to_return->get_next();
        }
        if (to_return == get_head()){
            set_head(nullptr);
        }
        temp->set_next(nullptr);
    }
    return to_return;
}

template <typename T>
T SinglyLinkedList<T>::peek_beginning(){
    if (head == nullptr){
        throw std::range_error("Cannot peek to the beginning of an empty list");
    }
    return head->get_value();
}

template <typename T>
void SinglyLinkedList<T>::display(){
    SinglyLinkedListNode<T>* temp = nullptr;
    temp = get_head();
    while(temp != nullptr){
        temp->display();
        temp = temp->get_next();
    }
}

template <typename T>
bool SinglyLinkedList<T>::is_empty(){
    if (head == nullptr) return true;
    return false;
}

template <typename T>
void SinglyLinkedList<T>::set_head(SinglyLinkedListNode<T>* p_head){
    head = p_head;
}

template <typename T>
SinglyLinkedListNode<T>* SinglyLinkedList<T>::get_head(){
    return head;
}

template class SinglyLinkedList<int>;
template class SinglyLinkedList<double>;
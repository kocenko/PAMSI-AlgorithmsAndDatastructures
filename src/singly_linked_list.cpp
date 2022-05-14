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
    SinglyLinkedListNode<T>* new_node = new SinglyLinkedListNode<T>(head, value);
    if(head == nullptr){
        set_head(new_node);
    }
    else{
        temp = get_head();
        while(temp != nullptr){
            temp = temp->get_next();
        }
        temp->set_next(new_node);
    }
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
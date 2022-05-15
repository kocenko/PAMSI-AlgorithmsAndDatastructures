#ifndef SINGLY_LINKED_LIST_HH
#define SINGLY_LINKED_LIST_HH

#include "singly_linked_list_node.hh"


template <typename T>
class SinglyLinkedList{
    private:
    SinglyLinkedListNode<T>* head;
    
    public:
    SinglyLinkedList();

    void add_node_at_beginning(T value);
    void add_node_at_end(T value);
    SinglyLinkedListNode<T>* remove_node_from_beginning();
    SinglyLinkedListNode<T>* remove_node_from_end();
    T peek_beginning();
    void display();
    bool is_empty();
    
    // Setters
    void set_head(SinglyLinkedListNode<T>* p_head);

    // Getters
    SinglyLinkedListNode<T>* get_head();
};

#endif  // SINGLY_LINKED_LIST_HH
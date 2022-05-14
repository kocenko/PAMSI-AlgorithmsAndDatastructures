#ifndef SINGLY_LINKED_LIST_NODE_HH
#define SINGLY_LINKED_LIST_NODE_HH

template <typename T>
class SinglyLinkedListNode{
private:
    SinglyLinkedListNode<T>* next;
    T value;
public:
    SinglyLinkedListNode(SinglyLinkedListNode<T>* p_next, T p_value);

    void display();

    // Setters
    void set_next(SinglyLinkedListNode<T>* p_next);

    // Getters
    SinglyLinkedListNode<T>* get_next();
    T get_value();
};

#endif  // SINGLY_LINKED_LIST_NODE_HH
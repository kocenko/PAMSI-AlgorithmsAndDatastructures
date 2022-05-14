#include <iostream>

#include "singly_linked_list.hh"


const int bob = 9;

int main(){
    SinglyLinkedList<int> list;

    for (int i=0; i<bob; i++){
        list.add_node_at_end(i);
    }

    for (int i=0; i<bob; i++){
        list.display();
        list.remove_node_from_beginning();
        std::cout << std::endl;
    }
}
#include <iostream>

#include "stack_list.hh"


const int max_size = 9;

int main(){
    StackLinkedList<int> stack;

    for (int i=0; i<max_size; i++){
        stack.push(i);
        std::cout << "Pushed: " << stack.peek() << std::endl;
    }

    for (int i=0; i<max_size; i++){
        std::cout << "Popped: " << stack.pop() << std::endl;
    }
}
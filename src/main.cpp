#include <iostream>

#include "stack.hh"


const int bob = 9;

int main(){
    StackLinkedList<int> stack;

    for (int i=0; i<bob; i++){
        stack.push(i);
        std::cout << "Pushed: " << stack.peek() << std::endl;
    }

    for (int i=0; i<bob; i++){
        std::cout << "Popped: " << stack.pop() << std::endl;
    }
}
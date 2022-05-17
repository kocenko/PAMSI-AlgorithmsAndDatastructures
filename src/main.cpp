#include <iostream>

#include "stack_list.hh"
#include "stack_array.hh"


const int max_size = 9;

int main(){
    StackArray<int> stack(max_size);

    for (int i=0; i<max_size; i++){
        stack.push(i);
        std::cout << "Pushed: " << stack.peek() << std::endl;
    }

    std::cout << std::endl;

    for (int i=0; i<max_size; i++){
        std::cout << "Popped: " << stack.pop() << std::endl;
    }
}
#include <iostream>

#include "stack_list.hh"
#include "stack_array.hh"
#include "queue_array.hh"


const int max_size = 9;

int main(){
    QueueArray<int> q(4);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    q.enqueue(4);
    q.dequeue();
    q.dequeue();
    q.display();

    // StackArray<int> stack(max_size);

    // for (int i=0; i<max_size; i++){
    //     stack.push(i);
    //     std::cout << "Pushed: " << stack.peek() << std::endl;
    // }

    // std::cout << std::endl;

    // for (int i=0; i<max_size; i++){
    //     std::cout << "Popped: " << stack.pop() << std::endl;
    // }
}
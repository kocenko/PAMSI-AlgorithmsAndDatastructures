#include <iostream>

#include "stack_list.hh"
#include "stack_array.hh"
#include "queue_array.hh"
#include "min_b_heap.hh"


int main(){
    MinBHeap<int> heap(3);
    int a=2, b=3, c=4, d=1, e=1, f=1, g=1;
    heap.insert(&a, 1);
    heap.insert(&b, 3);
    heap.insert(&c, 4);
    heap.insert(&d, 3);
    heap.insert(&e, 5);
    heap.insert(&f, 3);
    heap.insert(&g, 1);
    heap.display();
    heap.extract_max();
    heap.display();
    std::cout << "Max size: " << heap.get_size() << std::endl;
}
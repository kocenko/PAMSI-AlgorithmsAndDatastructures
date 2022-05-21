#include <iostream>

#include "stack_list.hh"
#include "stack_array.hh"
#include "queue_array.hh"
#include "min_b_heap.hh"


int main(){
    MinBHeap<int> heap(3);
    int a=2, b=3, c=4, d=1;
    heap.insert(&a, 2);
    heap.insert(&b, 1);
    heap.insert(&c, 4);
    heap.insert(&d, 2);
    heap.display();
    heap.extract_min();
    heap.display();
}
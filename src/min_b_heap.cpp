#include <iostream>
#include <cmath>

#include "min_b_heap.hh"
#include "heap_node.hh"


template <typename T>
MinBHeap<T>::MinBHeap(int initial_size){
    set_size(initial_size);
    array = new HeapNode<T>*[initial_size];
    for(int i=0; i<initial_size; i++){
        array[i] = nullptr;
    }
    set_add_idx(0);
}

template <typename T>
MinBHeap<T>::~MinBHeap(){
    delete array;
}

template <typename T>
void MinBHeap<T>::expand_array(){
    int current_size = get_size();
    int new_size = 2*current_size;
    HeapNode<T>** new_array = new HeapNode<T>*[new_size];

    for(int i=0; i<current_size; i++){
        new_array[i] = array[i];
    }
    delete array;

    array = new_array;
    set_size(new_size);
}

template <typename T>
void MinBHeap<T>::insert(T* new_element, int new_key){
    HeapNode<T>* new_node = new HeapNode<T>(new_element, new_key);
    
    if (add_idx >= max_size){
        std::cout << "Expanded array of the heap." << std::endl;
        expand_array();
    }

    array[add_idx] = new_node;
    upheap(add_idx);
    set_add_idx(add_idx+1);
}

template <typename T>
void MinBHeap<T>::upheap(int where_from){
    int parent_idx;
    
    if(where_from != 0){
        parent_idx = get_parent_idx(where_from);
        if(array[where_from]->get_key() < array[parent_idx]->get_key()){
            swap(where_from, parent_idx);
            upheap(parent_idx);
        }
    }
}

template <typename T>
void MinBHeap<T>::downheap(int where_from){
    int root_idx, smallest_idx, left_idx, right_idx, max_idx;

    root_idx = where_from;
    smallest_idx = where_from;
    left_idx = 2 * root_idx + 1;
    right_idx = 2 * root_idx + 2;
    max_idx = add_idx - 1;
    
    if(left_idx <= max_idx && array[smallest_idx]->get_key() > array[left_idx]->get_key()){
        smallest_idx = left_idx;
    }

    if(right_idx <= max_idx && array[smallest_idx]->get_key() > array[right_idx]->get_key()){
        smallest_idx = right_idx;
    }

    if(smallest_idx != root_idx){
        swap(root_idx, smallest_idx);
        downheap(smallest_idx);
    }
}

template <typename T>
void MinBHeap<T>::swap(int idx1, int idx2){
    HeapNode<T>* temp = array[idx2];
    array[idx2] = array[idx1];
    array[idx1] = temp;
}

template <typename T>
HeapNode<T>* MinBHeap<T>::extract_max(){
    int max_idx, max_value;

    if(is_empty()){
        throw std::out_of_range("Cannot extract maximum value from an empty heap");
    }
    
    max_idx = get_parent_idx(add_idx-1);
    max_value = array[max_idx]->get_key();
    
    for(int i=max_idx+1; i<add_idx; i++){
        if(array[i]->get_key() > max_value){
            max_idx = i;
            max_value = array[i]->get_key();
        }
    }

    swap(add_idx-1, max_idx);
    array[add_idx-1] = nullptr;
    set_add_idx(add_idx-1);

    // In case max index was not changed
    if(max_idx != add_idx && !is_empty()){
        upheap(max_idx);
        downheap(max_idx);
    }

    return array[max_idx];
}

template <typename T>
HeapNode<T>* MinBHeap<T>::extract_min(){
    HeapNode<T>* to_return = array[0];
    swap(0, add_idx-1);
    array[add_idx-1] = nullptr;
    set_add_idx(add_idx-1);
    downheap(0);

    return to_return;
}

template <typename T>
bool MinBHeap<T>::is_empty(){
    if(add_idx == 0) return true;
    return false;
}

template <typename T>
void MinBHeap<T>::display(){
    for(int i=0; i<add_idx; i++){
        std::cout << array[i]->get_key() << " ";
    }
    std::cout << std::endl;
}

template <typename T>
int MinBHeap<T>::get_parent_idx(int node_idx){
    if (node_idx == 0) return 0;
    return std::floor((node_idx-1)/2);
}

template <typename T>
int MinBHeap<T>::get_size(){
    return max_size;
}

template <typename T>
int MinBHeap<T>::get_add_idx(){
    return add_idx;
}

template <typename T>
void MinBHeap<T>::set_size(int new_size){
    max_size = new_size;
}

template <typename T>
void MinBHeap<T>::set_add_idx(int new_add_idx){
    add_idx = new_add_idx;
}

template class MinBHeap<int>;
template class MinBHeap<double>;

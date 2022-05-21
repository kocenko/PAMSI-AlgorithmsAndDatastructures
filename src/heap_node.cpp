#include "heap_node.hh"

template <typename T>
HeapNode<T>::HeapNode(T* param_element, int param_key){
    set_key(param_key);
    set_element(param_element);
}

template <typename T>
int HeapNode<T>::get_key(){
    return key;
}

template <typename T>
T* HeapNode<T>::get_element(){
    return element;
}

template <typename T>
void HeapNode<T>::set_key(int new_key){
    key = new_key;
}

template <typename T>
void HeapNode<T>::set_element(T* new_element){
    element = new_element;
}

template class HeapNode<int>;
template class HeapNode<double>;
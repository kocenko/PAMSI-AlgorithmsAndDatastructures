#include <stdexcept>

#include "stack_array.hh"


template <typename T>
StackArray<T>::StackArray(int size){
    set_max_size(size);
    set_top_idx(0);
    data = new T[size];

    for(int i=0; i<size; i++){
        data[i] = 0;
    }
}

template <typename T>
StackArray<T>::~StackArray(){
    delete data;
}

template <typename T>
void StackArray<T>::push(T element){
    if (top_idx == max_size){
        throw std::range_error("Stack is full");
    }
    data[top_idx] = element;
    top_idx ++;
}

template <typename T>
T StackArray<T>::pop(){
    T to_return = 0;
    if (top_idx == 0){
        throw std::range_error("Cannot pop from empty stack");
    }
    top_idx--;
    to_return = data[top_idx];
    data[top_idx] = 0;
    
    return to_return;
}

template <typename T>
T StackArray<T>::peek(){
    if (top_idx == 0){
        throw std::range_error("Cannot pop from empty stack");
    }
    return data[top_idx-1];
}

template <typename T>
void StackArray<T>::set_max_size(int new_size){
    max_size = new_size;
}

template <typename T>
void StackArray<T>::set_top_idx(int new_idx){
    top_idx = new_idx;
}

template class StackArray<int>;
template class StackArray<double>;

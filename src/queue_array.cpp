#include <iostream>

#include "queue_array.hh"


template <typename T>
QueueArray<T>::QueueArray(int size){
    set_max_size(size);
    set_front_idx(-1);
    set_end_idx(-1);
    data = new T[size];

    for(int i=0; i<size; i++){
        data[i] = 0;
    }
}

template <typename T>
QueueArray<T>::~QueueArray(){
    delete data;
}

template <typename T>
void QueueArray<T>::enqueue(T element){
    if(front_idx == 0 && end_idx == max_size-1 || (end_idx == (front_idx-1)%(max_size-1))){
        throw std::range_error("Queue is full");
    }
    else if(front_idx == -1){
        set_front_idx(0);
        set_end_idx(0);
    }
    else if(end_idx == max_size-1 && front_idx != 0){
        set_end_idx(0);
    }
    else{
        set_end_idx(end_idx+1);
    }
    data[end_idx] = element;
}

template <typename T>
T QueueArray<T>::dequeue(){
    T to_return;
    if(front_idx == -1){
        throw std::range_error("Queue is empty");
    }

    to_return = data[front_idx];

    if(front_idx == end_idx){
        set_front_idx(-1);
        set_end_idx(-1);
    }
    else if(front_idx == max_size-1){
        set_front_idx(0);
    }
    else{
        set_front_idx(front_idx + 1);
    }

    return to_return;
}

template <typename T>
void QueueArray<T>::display(){
    if(front_idx == -1){
        throw std::range_error("Queue is empty");
    }
    if(front_idx <= end_idx){
        for(int i=front_idx; i<=end_idx; i++){
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
    else{
        for(int i=front_idx; i<max_size; i++){
            std::cout << data[i] << " ";
        }
        for(int i=0; i<=end_idx; i++){
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
void QueueArray<T>::set_max_size(int new_size){
    max_size = new_size;
}

template <typename T>
void QueueArray<T>::set_end_idx(int new_end){
    end_idx = new_end;
}

template <typename T>
void QueueArray<T>::set_front_idx(int new_front){
    front_idx = new_front;
}

template class QueueArray<int>;
template class QueueArray<double>;

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
    if(front_idx == 0 && end_idx == max_size-1){

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

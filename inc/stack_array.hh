#ifndef STACK_ARRAY_HH
#define STACK_ARRAY_HH

#include "singly_linked_list.hh"


template <typename T>
class StackArray{
private:
    T* data;
    int max_size;
    int top_idx;
public:
    StackArray(int size);
    ~StackArray();

    void push(T element);
    T pop();
    T peek();

    // Setters
    void set_max_size(int new_size);
    void set_top_idx(int new_idx);
};

#endif  // STACK_ARRAY_HH
#ifndef MIN_B_HEAP_HH
#define MIN_B_HEAP_HH

#include "heap_node.hh"


template <typename T>
class MinBHeap{
private:
    HeapNode<T>** array;
    int max_size;
    int add_idx;
public:
    MinBHeap(int initial_size);
    ~MinBHeap();

    void expand_array();
    void insert(T* new_element, int new_key);
    void upheap(int where_from);
    void downheap(int where_from);
    void swap(int idx1, int idx2);
    HeapNode<T>* extract_max();
    HeapNode<T>* extract_min();
    bool is_empty();
    void display();

    // Getters
    int get_parent_idx(int node_idx);
    int get_size();
    int get_add_idx();

    // Setters
    void set_size(int new_size);
    void set_add_idx(int new_add_idx);
};

#endif  // MIN_B_HEAP_HH
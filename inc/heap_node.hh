#ifndef HEAP_NODE_HH
#define HEAP_NODE_HH


template<typename T>
class HeapNode{
private:
    int key;
    T* element;
public:
    HeapNode(T* param_element, int param_key);

    // Getters
    int get_key();
    T* get_element();

    // Setters
    void set_key(int new_key);
    void set_element(T* new_element);
};

#endif  // HEAP_NODE_HH
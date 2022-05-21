#ifndef QUEUE_ARRAY_HH
#define QUEUE_ARRAY_HH


template <typename T>
class QueueArray{
private:
    int max_size;
    int end_idx;
    int front_idx;
    T* data;
public:
    QueueArray(int size);
    ~QueueArray();

    void enqueue(T element);
    T dequeue();
    void display();

    // Setters
    void set_max_size(int new_size);
    void set_end_idx(int new_end);
    void set_front_idx(int new_front);
};

#endif  // QUEUE_ARRAY_HH
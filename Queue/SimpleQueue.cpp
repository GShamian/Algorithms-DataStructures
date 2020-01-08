#include <iostream>

struct Queue {
    int head, tail, size;
    unsigned capacity;
    int *arr;
};

Queue *create(unsigned capacity) {
    Queue *queue = new Queue();
    queue->capacity = capacity;
    queue->head = queue->size = 0;
    queue->tail = capacity - 1;
    queue->arr = new int[capacity * sizeof(int)];
    return queue;
}

bool isFull(Queue *queue) {
    return queue->size == queue->capacity;
}

bool isEmpty(Queue *queue) {
    return queue->size == 0;
}

void enqueue(Queue *queue, int item) {
    if (!isFull(queue)) {
        queue->tail = (queue->tail + 1) % queue->capacity;
        queue->arr[queue->tail] = item;
        ++queue->size;
    }
}

int dequeue(Queue *queue) {
    int item = queue->arr[queue->head];
    if (!isEmpty(queue)) {
        queue->head = (queue->head + 1) % queue->capacity;
        --queue->size;
    }
    return item;
}


int main() {
    Queue *queue = create(100);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    std::cout << queue->size << std::endl;
    std::cout << dequeue(queue) << " " << queue->size << std::endl;

    return 0;
}

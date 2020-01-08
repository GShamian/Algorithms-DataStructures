#include <iostream>

struct Stack{
    int top, size;
    unsigned capacity;
    int *arr;
};

Stack* create(unsigned capacity) {
    Stack* stack = new Stack();
    stack->capacity = capacity;
    stack->top = stack->size = 0;
    stack->arr = new int[capacity * sizeof(int)];
    return stack;
}

bool isEmpty(Stack *stack) {
    return stack->size == 0;
}

bool isFull(Stack* stack) {
    return stack->size == stack->capacity;
}

void push(Stack* stack, int item) {
    if (!isFull(stack)) {
        stack->top = (stack->top + 1) % stack->capacity;
        stack->arr[stack->top] = item;
        ++stack->size;
    }
}

int pop(Stack* stack) {
    int item = stack->arr[stack->top];
    if (!isEmpty(stack)) {
        stack->top = (stack->top - 1) % stack->capacity;
        --stack->size;
    }
    return item;
}

int main() {
    Stack* stack = create(100);

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);

    std::cout << stack->size << std::endl;

    std::cout << pop(stack) << " " << stack->arr[stack->top];

    return 0;
}

#include <stdio.h>

class FixedIntStack 
{
    int* arr;
    int capacity;
    int topIdx;
public:
    
    FixedIntStack(int size) {
        capacity = size;
        arr = new int[capacity];
        topIdx = -1;
    }
    
    ~FixedIntStack() { delete[] arr; }
    
    void push(int x) {
        if (topIdx + 1 < capacity)
            arr[++topIdx] = x;
        else
            printf("%s", "Stack overflow\n");
    }
    
    void pop() {
        if (topIdx >= 0)
            topIdx--;
        else
            printf("%s", "Stack underflow\n");
    }
    
    int top() { return arr[topIdx]; }
    
    bool empty() { return topIdx == -1; }
    
    int size() { return topIdx + 1; }
};

int main()
{
    // FixedIntStack with capacity 5
    FixedIntStack *s = new FixedIntStack(5);  
    
    printf("Memory Address: %p\n", *s);

    s->push(10);
    s->push(20);
    s->push(30);

    printf("Top: %d\n", s->top());
    printf("Size: %d\n", s->size());
    
    delete s;
    // Commenting this line will lead to Undefined Behavior 
    s = nullptr;
    
    // Not Defined
    if (s) {
        printf("s had been deleted and not dangled");    
    } else {
        printf("Undefined Behavior: %d", s->top());
    }
    
    return 0;
}
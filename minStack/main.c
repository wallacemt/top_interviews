#include <stdlib.h>

typedef struct {
    int* data;
    int size;
    int capacity;
    int min;
} MinStack;

MinStack* minStackCreate() {
    MinStack* stack = (MinStack*)malloc(sizeof(MinStack));
    stack->capacity = 2;
    stack->data = (int*)malloc(sizeof(int) * stack->capacity);
    stack->size = 0;
    stack->min = INT_MAX;
    return stack;
}

void minStackPush(MinStack* obj, int val) {
    if (obj->size == obj->capacity) {
        obj->capacity *= 2;
        obj->data = (int*)realloc(obj->data, sizeof(int) * obj->capacity);
    }
    obj->data[obj->size++] = val;
    obj->min = obj->min < val ? obj->min : val;
}

void minStackPop(MinStack* obj) {
    if (obj->size == 0) return;
    obj->size--;
    if (obj->data[obj->size] == obj->min) {
        int min = INT_MAX;
        for (int i = 0; i < obj->size; i++) {
            min = min < obj->data[i] ? min : obj->data[i];
        }
        obj->min = min;
    }
    if (obj->size == obj->capacity / 4) {
        obj->capacity /= 2;
        obj->data = (int*)realloc(obj->data, sizeof(int) * obj->capacity);
    }
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->size - 1];
}

int minStackGetMin(MinStack* obj) {
    return obj->min;

}
void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj);
}


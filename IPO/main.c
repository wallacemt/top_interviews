#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int profit;
    int capital;
} Project;

typedef struct {
    int* heap;
    int size;
    int capacity;
} MaxHeap;

MaxHeap* createMaxHeap(int capacity) {
    MaxHeap* heap = malloc(sizeof(MaxHeap));
    heap->heap = malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void heapifyUp(MaxHeap* heap, int index) {
    if (index == 0) return;
    int parent = (index - 1) / 2;
    if (heap->heap[index] > heap->heap[parent]) {
        int temp = heap->heap[index];
        heap->heap[index] = heap->heap[parent];
        heap->heap[parent] = temp;
        heapifyUp(heap, parent);
    }
}

void heapifyDown(MaxHeap* heap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    
    if (left < heap->size && heap->heap[left] > heap->heap[largest])
        largest = left;
    if (right < heap->size && heap->heap[right] > heap->heap[largest])
        largest = right;
    
    if (largest != index) {
        int temp = heap->heap[index];
        heap->heap[index] = heap->heap[largest];
        heap->heap[largest] = temp;
        heapifyDown(heap, largest);
    }
}

void push(MaxHeap* heap, int value) {
    heap->heap[heap->size] = value;
    heapifyUp(heap, heap->size);
    heap->size++;
}

int pop(MaxHeap* heap) {
    if (heap->size == 0) return -1;
    int max = heap->heap[0];
    heap->heap[0] = heap->heap[heap->size - 1];
    heap->size--;
    if (heap->size > 0) heapifyDown(heap, 0);
    return max;
}

int compareCapital(const void* a, const void* b) {
    return ((Project*)a)->capital - ((Project*)b)->capital;
}

int findMaximizedCapital(int k, int w, int* profits, int profitsSize, int* capital, int capitalSize) {
    Project projects[profitsSize];
    for (int i = 0; i < profitsSize; ++i) {
        projects[i].profit = profits[i];
        projects[i].capital = capital[i];
    }
    
    qsort(projects, profitsSize, sizeof(Project), compareCapital);
    
    MaxHeap* heap = createMaxHeap(profitsSize);
    int currentCapital = w;
    int projectIndex = 0;
    
    for (int count = 0; count < k; count++) {
        while (projectIndex < profitsSize && projects[projectIndex].capital <= currentCapital) {
            push(heap, projects[projectIndex].profit);
            projectIndex++;
        }
        
        if (heap->size == 0) break;
        
        currentCapital += pop(heap);
    }
    
    free(heap->heap);
    free(heap);
    return currentCapital;
}

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    long long sum;
    int i, j;
} Pair;

typedef struct {
    Pair* heap;
    int size;
    int capacity;
} MinHeap;

MinHeap* createHeap(int capacity) {
    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    h->heap = (Pair*)malloc(capacity * sizeof(Pair));
    h->size = 0;
    h->capacity = capacity;
    return h;
}

void swap(Pair* a, Pair* b) {
    Pair temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MinHeap* h, int idx) {
    if (idx == 0) return;
    int parent = (idx - 1) / 2;
    if (h->heap[idx].sum < h->heap[parent].sum) {
        swap(&h->heap[idx], &h->heap[parent]);
        heapifyUp(h, parent);
    }
}

void heapifyDown(MinHeap* h, int idx) {
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    int smallest = idx;
    
    if (left < h->size && h->heap[left].sum < h->heap[smallest].sum)
        smallest = left;
    if (right < h->size && h->heap[right].sum < h->heap[smallest].sum)
        smallest = right;
        
    if (smallest != idx) {
        swap(&h->heap[idx], &h->heap[smallest]);
        heapifyDown(h, smallest);
    }
}

void push(MinHeap* h, long long sum, int i, int j) {
    if (h->size >= h->capacity) return;
    h->heap[h->size] = (Pair){sum, i, j};
    heapifyUp(h, h->size);
    h->size++;
}

Pair pop(MinHeap* h) {
    Pair min = h->heap[0];
    h->heap[0] = h->heap[h->size - 1];
    h->size--;
    heapifyDown(h, 0);
    return min;
}

int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize, int** returnColumnSizes) {
    long long maxPairs = (long long)nums1Size * nums2Size;
    *returnSize = (k < maxPairs) ? k : (int)maxPairs;
    
    int** result = (int**)malloc(*returnSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(*returnSize * sizeof(int));
    
    for (int i = 0; i < *returnSize; i++) {
        result[i] = (int*)malloc(2 * sizeof(int));
        (*returnColumnSizes)[i] = 2;
    }
    
    MinHeap* heap = createHeap(nums1Size);
    
    for (int i = 0; i < nums1Size; i++) {
        push(heap, (long long)nums1[i] + nums2[0], i, 0);
    }
    
    for (int count = 0; count < *returnSize; count++) {
        Pair min = pop(heap);
        result[count][0] = nums1[min.i];
        result[count][1] = nums2[min.j];
        
        if (min.j + 1 < nums2Size) {
            push(heap, (long long)nums1[min.i] + nums2[min.j + 1], min.i, min.j + 1);
        }
    }
    
    free(heap->heap);
    free(heap);
    return result;
}

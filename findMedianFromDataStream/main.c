#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* maxHeap;  
    int* minHeap;  
    int maxSize;
    int minSize;
    int maxCapacity;
    int minCapacity;
} MedianFinder;

void maxHeapify(int* heap, int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < size && heap[left] > heap[largest])
        largest = left;
    if (right < size && heap[right] > heap[largest])
        largest = right;
    
    if (largest != i) {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        maxHeapify(heap, size, largest);
    }
}

void minHeapify(int* heap, int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;
    
    if (smallest != i) {
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        minHeapify(heap, size, smallest);
    }
}

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    obj->maxCapacity = obj->minCapacity = 1000;
    obj->maxHeap = (int*)malloc(obj->maxCapacity * sizeof(int));
    obj->minHeap = (int*)malloc(obj->minCapacity * sizeof(int));
    obj->maxSize = obj->minSize = 0;
    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    if (obj->maxSize == 0 || num <= obj->maxHeap[0]) {
        if (obj->maxSize == obj->maxCapacity) {
            obj->maxCapacity *= 2;
            obj->maxHeap = (int*)realloc(obj->maxHeap, obj->maxCapacity * sizeof(int));
        }
        obj->maxHeap[obj->maxSize] = num;
        for (int i = obj->maxSize; i > 0 && obj->maxHeap[(i-1)/2] < obj->maxHeap[i]; i = (i-1)/2) {
            int temp = obj->maxHeap[i];
            obj->maxHeap[i] = obj->maxHeap[(i-1)/2];
            obj->maxHeap[(i-1)/2] = temp;
        }
        obj->maxSize++;
    } else {
        if (obj->minSize == obj->minCapacity) {
            obj->minCapacity *= 2;
            obj->minHeap = (int*)realloc(obj->minHeap, obj->minCapacity * sizeof(int));
        }
        obj->minHeap[obj->minSize] = num;
        for (int i = obj->minSize; i > 0 && obj->minHeap[(i-1)/2] > obj->minHeap[i]; i = (i-1)/2) {
            int temp = obj->minHeap[i];
            obj->minHeap[i] = obj->minHeap[(i-1)/2];
            obj->minHeap[(i-1)/2] = temp;
        }
        obj->minSize++;
    }
    
    if (obj->maxSize > obj->minSize + 1) {
        int val = obj->maxHeap[0];
        obj->maxHeap[0] = obj->maxHeap[obj->maxSize - 1];
        obj->maxSize--;
        maxHeapify(obj->maxHeap, obj->maxSize, 0);
        
        if (obj->minSize == obj->minCapacity) {
            obj->minCapacity *= 2;
            obj->minHeap = (int*)realloc(obj->minHeap, obj->minCapacity * sizeof(int));
        }
        obj->minHeap[obj->minSize] = val;
        for (int i = obj->minSize; i > 0 && obj->minHeap[(i-1)/2] > obj->minHeap[i]; i = (i-1)/2) {
            int temp = obj->minHeap[i];
            obj->minHeap[i] = obj->minHeap[(i-1)/2];
            obj->minHeap[(i-1)/2] = temp;
        }
        obj->minSize++;
    } else if (obj->minSize > obj->maxSize + 1) {
        int val = obj->minHeap[0];
        obj->minHeap[0] = obj->minHeap[obj->minSize - 1];
        obj->minSize--;
        minHeapify(obj->minHeap, obj->minSize, 0);
        
        if (obj->maxSize == obj->maxCapacity) {
            obj->maxCapacity *= 2;
            obj->maxHeap = (int*)realloc(obj->maxHeap, obj->maxCapacity * sizeof(int));
        }
        obj->maxHeap[obj->maxSize] = val;
        for (int i = obj->maxSize; i > 0 && obj->maxHeap[(i-1)/2] < obj->maxHeap[i]; i = (i-1)/2) {
            int temp = obj->maxHeap[i];
            obj->maxHeap[i] = obj->maxHeap[(i-1)/2];
            obj->maxHeap[(i-1)/2] = temp;
        }
        obj->maxSize++;
    }
}

double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->maxSize > obj->minSize) {
        return (double)obj->maxHeap[0];
    } else if (obj->minSize > obj->maxSize) {
        return (double)obj->minHeap[0];
    } else {
        return (obj->maxHeap[0] + obj->minHeap[0]) / 2.0;
    }
}

void medianFinderFree(MedianFinder* obj) {
    free(obj->maxHeap);
    free(obj->minHeap);
    free(obj);
}

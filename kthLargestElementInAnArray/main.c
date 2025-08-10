typedef struct {
    int val;
    int idx;
} HeapNode;

void swapNodes(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(HeapNode* heap, int heapSize, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && heap[left].val > heap[largest].val) {
        largest = left;
    }

    if (right < heapSize && heap[right].val > heap[largest].val) {
        largest = right;
    }

    if (largest != i) {
        swapNodes(&heap[i], &heap[largest]);
        heapify(heap, heapSize, largest);
    }
}
int findKthLargest(int* nums, int numsSize, int k) {
    HeapNode heap[numsSize];

    for (int i = 0; i < numsSize; i++) {
        heap[i].val = nums[i];
        heap[i].idx = i;
    }

    int heapSize = numsSize;
    for (int i = numsSize / 2 - 1; i >= 0; i--) {
        heapify(heap, heapSize, i);
    }

    for (int i = 0; i < k - 1; i++) {
        swapNodes(&heap[0], &heap[heapSize - 1]);
        heapSize--;
        heapify(heap, heapSize, 0);
    }

    return heap[0].val;
}

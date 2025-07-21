#include <stdlib.h>
#include <stdbool.h>

void backtrack(int l, int r, int n, int k, bool* arr, int** output, int* returnSize) {
    if (l == r + 1) { 
        int a = 0;
        for (int i = 1; i <= r; ++i) {
            if (arr[i]) {
                output[*returnSize][a++] = i;
            }
        }
        (*returnSize)++;
        return;
    }

    if (n >= 1) {  
        arr[l] = true;
        backtrack(l + 1, r, n - 1, k, arr, output, returnSize);
    }

    if (r - l + 1 > n) { 
        arr[l] = false;
        backtrack(l + 1, r, n, k, arr, output, returnSize);
    }
}
int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    int total = 1;
    for (int i = 0; i < k; ++i) {
        total *= (n - i);
        total /= (i + 1);
    }
    bool arr[n + 1]; 
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * total);
    int** output = (int**)malloc(sizeof(int*) * total);
    
    for (int i = 0; i < total; ++i) {
        (*returnColumnSizes)[i] = k;
        output[i] = (int*)malloc(sizeof(int) * k);
    }
    backtrack(1, n, k, k, arr, output, returnSize);
    return output;
}

int compare(const void* a, const void* b) {
    int* interval1 = *(int**)a;
    int* interval2 = *(int**)b;
    return interval1[0] - interval2[0];
}

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    int** result = malloc(sizeof(int*) * (intervalsSize + 1));
    *returnColumnSizes = malloc(sizeof(int) * (intervalsSize + 1));
    *returnSize = 0;

    int i = 0;
    while (i < intervalsSize && intervals[i][1] < newInterval[0]) {
        result[*returnSize] = malloc(sizeof(int) * 2);
        result[*returnSize][0] = intervals[i][0];
        result[*returnSize][1] = intervals[i][1];
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;
        i++;
    }
    int start = newInterval[0];
    int end = newInterval[1];
    while (i < intervalsSize && intervals[i][0] <= end) {
        start = start < intervals[i][0] ? start : intervals[i][0];
        end = end > intervals[i][1] ? end : intervals[i][1];
        i++;
    }
    result[*returnSize] = malloc(sizeof(int) * 2);
    result[*returnSize][0] = start;
    result[*returnSize][1] = end;
    (*returnColumnSizes)[*returnSize] = 2;
    (*returnSize)++;
    while (i < intervalsSize) {
        result[*returnSize] = malloc(sizeof(int) * 2);
        result[*returnSize][0] = intervals[i][0];
        result[*returnSize][1] = intervals[i][1];
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;
        i++;
    }

    return result;
}


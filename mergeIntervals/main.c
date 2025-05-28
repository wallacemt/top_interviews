int compare(const void *a, const void *b)
{
    int* intervalA = *(int**)a;
    int* intervalB = *(int**)b;
    return intervalA[0] - intervalB[0];
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * intervalsSize);
    int** result = malloc(sizeof(int*) * intervalsSize);
    if (intervalsSize == 0) return result;

    qsort(intervals, intervalsSize, sizeof(int*), compare);

    result[(*returnSize)++] = malloc(sizeof(int) * 2);
    result[0][0] = intervals[0][0];
    result[0][1] = intervals[0][1];
    (*returnColumnSizes)[0] = 2;

    for (int i = 1; i < intervalsSize; i++)
    {
        if (result[*returnSize - 1][1] >= intervals[i][0])
        {
            if (result[*returnSize - 1][1] < intervals[i][1])
                result[*returnSize - 1][1] = intervals[i][1];
        }
        else
        {
            result[(*returnSize)++] = malloc(sizeof(int) * 2);
            result[*returnSize - 1][0] = intervals[i][0];
            result[*returnSize - 1][1] = intervals[i][1];
            (*returnColumnSizes)[*returnSize - 1] = 2;
        }
    }

    return result;
}


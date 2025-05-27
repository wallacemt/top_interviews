char* formatRange(int start, int end) {
    int size;
    if (start == end) {
        size = snprintf(NULL, 0, "%d", start) + 1;
    } else {
        size = snprintf(NULL, 0, "%d->%d", start, end) + 1;
    }
    char* range = malloc(size);
    if (range == NULL) {
        return NULL;
    }
    if (start == end) {
        sprintf(range, "%d", start);
    } else {
        sprintf(range, "%d->%d", start, end);
    }
    return range;
}

char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    char** result = malloc(sizeof(char*) * (numsSize + 1));
    *returnSize = 0;
    int start = nums[0];
    int end = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == end + 1) {
            end = nums[i];
        } else {
            result[(*returnSize)++] = formatRange(start, end);
            start = nums[i];
            end = nums[i];
        }
    }
    result[(*returnSize)++] = formatRange(start, end);
    result[*returnSize] = NULL;
    return result;
}

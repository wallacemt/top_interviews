int hIndex(int* citations, int citationsSize) {
    int h = 0;
    int count[citationsSize + 1];
    memset(count, 0, sizeof(count));

    for (int i = 0; i < citationsSize; i++) {
        count[citations[i] > citationsSize ? citationsSize : citations[i]]++;
    }

    for (int i = citationsSize; i > 0; i--) {
        h += count[i];
        if (h >= i) {
            return i;
        }
    }

    return 0;
}


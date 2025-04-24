int candy(int* ratings, int ratingsSize) {
    int candy = 1, prev = 1, up = 0, down = 0;
    for (int i = 1; i < ratingsSize; i++) {
        if (ratings[i] > ratings[i - 1]) {
            up = down = 0;
            prev = prev + 1;
        } else if (ratings[i] < ratings[i - 1]) {
            down = down + 1;
            prev = 1;
            up = 0;
        } else {
            up = down = 0;
            prev = 1;
        }
        candy += prev + max(up, down);
    }
    return candy;
}


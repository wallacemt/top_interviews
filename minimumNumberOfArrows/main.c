#include <stdio.h>
#include <stdlib.h>

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
    if (pointsSize == 0) return 0;

    int arrows = 1;
    int end = points[0][1];

    for (int i = 1; i < pointsSize; i++) {
        if (points[i][0] > end) {
            arrows++;
            end = points[i][1];
        } else if (points[i][1] < end) {
            end = points[i][1];
        }
    }

    return arrows;
}


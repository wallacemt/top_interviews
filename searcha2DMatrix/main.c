bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int left = 0, right = matrixSize * (*matrixColSize) - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midValue = matrix[mid / (*matrixColSize)][mid % (*matrixColSize)];
        if (midValue == target) {
            return true;
        } else if (midValue < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}
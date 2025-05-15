int *spiralOrder(int **matrix, int matrixSize, int *matrixColSize, int *returnSize)
{
    if (matrixSize == 0 || matrixColSize[0] == 0)
    {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = matrixSize * matrixColSize[0];
    int *result = malloc(sizeof(int) * (*returnSize)); 
    if (!result) return NULL;

    int top = 0, bottom = matrixSize - 1, left = 0, right = matrixColSize[0] - 1;
    int index = 0;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            if (index < *returnSize) result[index++] = matrix[top][i];
        }
        top++;

        for (int i = top; i <= bottom && left <= right; i++)
        {
            if (index < *returnSize) result[index++] = matrix[i][right];
        }
        right--;

        for (int i = right; i >= left && top <= bottom; i--)
        {
            if (index < *returnSize) result[index++] = matrix[bottom][i];
        }
        bottom--;

        for (int i = bottom; i >= top && left <= right; i--)
        {
            if (index < *returnSize) result[index++] = matrix[i][left];
        }
        left++;
    }

    return result;
}


void rotate(int **matrix, int matrixSize, int *matrixColSize){
    for (int i = 0; i < matrixSize / 2; i++)
    {
        for (int j = i; j < matrixSize - i - 1; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[matrixSize - 1 - j][i];
            matrix[matrixSize - 1 - j][i] = matrix[matrixSize - 1 - i][matrixSize - 1 - j];
            matrix[matrixSize - 1 - i][matrixSize - 1 - j] = matrix[j][matrixSize - 1 - i];
            matrix[j][matrixSize - 1 - i] = temp;
        }
    }
    
    return;
}


double myPow(double x, int n) {
    long long absN = (n < 0) ? -(long long)n : n;
    double result = 1;
    double currentProduct = x;
    
    while (absN > 0) {
        if (absN % 2 == 1) {
            result *= currentProduct;
        }
        currentProduct *= currentProduct;
        absN /= 2;
    }
    
    return (n < 0) ? 1 / result : result;
}
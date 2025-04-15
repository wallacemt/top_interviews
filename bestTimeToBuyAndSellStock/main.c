int maxProfit(int* prices, int pricesSize) {
    int profit = 0, min = prices[0];
    for(int i = 1; i < pricesSize; i++) {
        min = min < prices[i] ? min : prices[i];
        profit = profit < prices[i] - min ? prices[i] - min : profit;
    }
    return profit;
}
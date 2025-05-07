int maxArea(int* height, int heightSize) {
    int left = 0, right = heightSize - 1, res = 0;
    while (left < right) {
        int minHeight = height[left] < height[right] ? height[left] : height[right];
        res = res < (right - left) * minHeight ? (right - left) * minHeight : res;
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return res;
}

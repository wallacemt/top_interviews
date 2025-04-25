int trap(int* height, int heightSize) {
    int left = 0, right = heightSize - 1, leftMax = 0, rightMax = 0, res = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] > leftMax) {
                leftMax = height[left];
            } else {
                res += leftMax - height[left];
            }
            left++;
        } else {
            if (height[right] > rightMax) {
                rightMax = height[right];
            } else {
                res += rightMax - height[right];
            }
            right--;
        }
    }
    return res;

}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int dummy[2000];
    int i=0, j=0, k=0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            dummy[k++] = nums1[i++];
        } else {
            dummy[k++] = nums2[j++];
        }
    }
    while (i < nums1Size) {
        dummy[k++] = nums1[i++];
    }
    while (j < nums2Size) {
        dummy[k++] = nums2[j++];
    }
    int n = nums1Size + nums2Size;
    if (n % 2) {
        return dummy[n / 2];
    } else {
        return (dummy[n / 2 - 1] + dummy[n / 2]) / 2.0;
    }
    return 0.0; // This line is never reached, but added to avoid compiler warnings.
}
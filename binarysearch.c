#include <stdio.h>

int binarySearch(int arr[], int left, int right, int key) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] > key) {
            return binarySearch(arr, left, mid - 1, key);
        }
        return binarySearch(arr, mid + 1, right, key);
    }

    return -1;
}

int main() {
    int arr[8], i, key, ans;

    printf("Enter 8 sorted numbers:\n");
    for (i = 0; i < 8; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter key: ");
    scanf("%d", &key);

    ans = binarySearch(arr, 0, 7, key);

    if (ans != -1) {
        printf("Element found at index: %d\n", ans);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}

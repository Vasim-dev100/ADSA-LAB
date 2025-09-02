
#include <stdio.h>


int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) return mid;
        else if (arr[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}


int ternarySearch(int arr[], int l, int r, int key) {
    while (l <= r) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        if (arr[mid1] == key) return mid1;
        if (arr[mid2] == key) return mid2;

        if (key < arr[mid1]) r = mid1 - 1;
        else if (key > arr[mid2]) l = mid2 + 1;
        else { l = mid1 + 1; r = mid2 - 1; }
    }
    return -1;
}


int main() {
    int n, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter sorted elements:\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    int res1 = binarySearch(arr, 0, n - 1, key);
    int res2 = ternarySearch(arr, 0, n - 1, key);

    if (res1 != -1) printf("Binary Search: Found at index %d\n", res1);
    else printf("Binary Search: Not Found\n");

    if (res2 != -1) printf("Ternary Search: Found at index %d\n", res2);
    else printf("Ternary Search: Not Found\n");

    return 0;
}


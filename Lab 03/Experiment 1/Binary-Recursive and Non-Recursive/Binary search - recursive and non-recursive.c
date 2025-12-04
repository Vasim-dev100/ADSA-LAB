// Online C compiler to run C program online
#include <stdio.h>

// Recursive Binary Search
int binarySearchRecursive(int arr[], int left, int right, int key) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid; // Key found
        else if (arr[mid] > key)
            return binarySearchRecursive(arr, left, mid - 1, key);
        else
            return binarySearchRecursive(arr, mid + 1, right, key);
    }
    return -1; // Key not found
}

// Iterative (Non-Recursive) Binary Search
int binarySearchIterative(int arr[], int n, int key) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid; // Key found
        else if (arr[mid] > key)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1; // Key not found
}

int main() {
    int n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted integers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the key to search: ");
    scanf("%d", &key);

    // Recursive search
    int recResult = binarySearchRecursive(arr, 0, n - 1, key);
    if (recResult != -1)
        printf("Recursive: Key %d found at index %d\n", key, recResult);
    else
        printf("Recursive: Key %d not found\n", key);

    // Iterative search
    int iterResult = binarySearchIterative(arr, n, key);
    if (iterResult != -1)
        printf("Iterative: Key %d found at index %d\n", key, iterResult);
    else
        printf("Iterative: Key %d not found\n", key);

    return 0;
}

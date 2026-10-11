#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
int low = 0, high = n - 1, mid;
while (low <= high) {
    mid = low + (high - low) / 2;      // avoid overflow
    if (arr[mid] == key) {
        return mid;
    }
    else if (arr[mid] < key) {
        low = mid + 1;
    }
    else {
        high = mid - 1;
    }
}
return -1;
}

int binarySearchRec(int arr[], int low, int high, int key) {
if (low > high) {
    return -1;      // not found
}
int mid = low + (high - low) / 2;
if (arr[mid] == key) {
    return mid;
}
else if (arr[mid] < key) {
    return binarySearchRec(arr, mid + 1, high, key);
}
else {
    return binarySearchRec(arr, low, mid - 1, key);
}
}

int main(){
int arr[] = {12, 23, 34, 45, 56, 67, 78, 90};
int n = sizeof(arr) / sizeof(arr[0]);
int key, a, b;
printf("Enter key to search: ");
scanf("%d", &key);
a = binarySearch(arr, n, key);
b = binarySearchRec(arr, 0, n - 1, key);
if (a == -1) {
    printf("key not found\n");
} else {
    printf("iterative: key found at index: %d\n", a);
    printf("recursive: key found at index: %d\n", b);
}
return 0;
}

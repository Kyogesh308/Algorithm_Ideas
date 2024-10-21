//Yogesh's Interpolation Search
#include <stdio.h>
#define MAX 100
// Yogesh Variant of Interpolation Search function
int variantInterpolationSearch(int arr[], int size, int key) {
    int i, mid, diff, quotient;

    diff = arr[size - 1] - arr[0];
    quotient = diff / key;
    mid = size / 2;

    if (arr[mid] == key) {
        return mid;
    } else if (arr[mid] > key) {
        i = mid;
        while (i >= 0) {
            if (arr[i - quotient - 1] == key) {
                return i - quotient - 1;
            } else if (arr[i - quotient - 1] < key) {
                for (int j = i - quotient - 1; j < i; j++) {
                    if (arr[j] == key) {
                        return j;
                    }
                }
            }
            i--;
        }
    } else {
        i = size - 1;
        while (i != mid) {
            if (arr[i - quotient - 1] == key) {
                return i - quotient - 1;
            } else if (arr[i - quotient - 1] < key) {
                for (int j = i - quotient - 1; j < i; j++) {
                    if (arr[j] == key) {
                        return j;
                    }
                }
            }
            i--;
        }
    }
    return -1; // not found
}

int main() {
    int arr[MAX], size, key;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter %d elements (sorted): ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the key value: ");
    scanf("%d", &key);
    int result = variantInterpolationSearch(arr, size, key);
    if (result != -1) {
        printf("Element found at %d location.\n", result + 1);
    } else {
        printf("Element not found.\n");
    }
    return 0;
}

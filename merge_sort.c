#include <stdio.h>
#include <stdlib.h>


void merge(int arr[], int left, int midpoint, int right) {

    int left_left = left;
    int right_right = right;

    int right_left = midpoint + 1;

    int new_array_size = right + 1;
    int new_array[new_array_size];
    int ni = left_left;

    while (left_left <= midpoint && right_left <= right_right) {
        if (arr[left_left] < arr[right_left]) {
            new_array[ni++] = arr[left_left++];
        } else {
            new_array[ni++] = arr[right_left++];
        }
    }

    while (left_left <= midpoint) {
        new_array[ni++] = arr[left_left++];
    }

    while (right_left <= right_right) {
        new_array[ni++] = arr[right_left++];
    }

    for (int i = left; i <= right; i++) {
        arr[i] = new_array[i];
    }
}

void merge_sort(int arr[], int left, int right) {
    int midpoint;

    if (left < right) {
        midpoint = (left + right) / 2;
        merge_sort(arr, left, midpoint);
        merge_sort(arr, midpoint + 1, right);
        merge(arr, left, midpoint, right);
    }
}

int main() {
    int arr[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int size = 10;
    int left = 0;
    int right = size - 1;

    merge_sort(arr, left, right);

    for (int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }
}

// arr1 = [38, 27, 43, 3];
// arr2 = [9, 82, 10];

// result_arr = [3, 9, 10, 27, 38, 43, 82];

// result_arr[100];
// arr1 = [3, 27, 38, 43]   arr2 = [9, 10, 82]
// i1 = 1      ,     i2 = 1
// i3 = 2;

// result_arr = [3, 38, 27]




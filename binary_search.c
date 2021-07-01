#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int binary_search(int arr[], int first_index, int last_index, int x) {
    while (first_index <= last_index) {
        int midpoint = (first_index + last_index) / 2;

        if (arr[midpoint] == x) {
            return midpoint;
        }

        if (arr[midpoint] < x) {
            first_index = midpoint + 1;
        }

        else {
            last_index = midpoint - 1;
        }
    }

    return -1;
}

int main()
{
    int n = 5;
    int arr[] = {1, 2, 3, 4, 5};

    int index = binary_search(arr, 0, n - 1, 2);

    printf("%d\n", index);

    return 0;
}
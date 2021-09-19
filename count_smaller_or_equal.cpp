# include <bits/stdc++.h>
using namespace std;

/* We can solving this problem via a modified binary search algorithm.
 * If the middle element is greater than the given element, we will update right index as "midpoint - 1".
 * If the middle element is less than or equal to the key update "count" as "midpoint+1" and "left_pointer" as "midpoint+1".
 * */

int countBinarySearch(int arr[], int size, int limit) {
    int left = 0;
    int right = size - 1;
    int count = size;

    while (left <= right) {
        int midpoint = (left + right) / 2;

        cout << "midpoint: " << midpoint << ", midvalue: " << arr[midpoint] << endl;

        if (arr[midpoint] >= limit) {
            cout << "Went right " << endl;

            count = midpoint;
            right = midpoint - 1;

        } else {
            cout << "Went left " << endl;

            left = midpoint + 1;
        }

        cout << endl;
    }

    return (size - count);
}

int main() {
    int arr[] = {2, 3, 5, 6, 6, 9};
    //---------- 0  1  2   3   4   5;
    int limit = 8;
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << countBinarySearch(arr, n, limit) << endl;

    return 0;
}
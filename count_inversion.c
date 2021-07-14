#include <stdio.h>
#include <stdlib.h>

typedef long long int ll;

ll range(ll *arr, ll left, ll midpoint, ll right) {
    ll left_left = left;
    ll left_right = midpoint - 1;

    ll right_right = right;

    ll right_left = midpoint;

    ll new_array_size = right + 1;
    ll new_array[new_array_size];
    ll ni = left_left;

    ll invertion_count = 0;

    while ((left_left <= left_right) && (right_left <= right_right)) {
        if (arr[left_left] <= arr[right_left]) {
            new_array[ni++] = arr[left_left++];

        } else {
            new_array[ni++] = arr[right_left++];

            invertion_count = invertion_count + (midpoint - left_left);
        }
    }

    while (left_left <= left_right) {
        new_array[ni++] = arr[left_left++];
    }

    while (right_left <= right_right) {
        new_array[ni++] = arr[right_left++];
    }

    for (ll i = left; i <= right; i++) {
        arr[i] = new_array[i];
    }

    return invertion_count;
}

ll segment_sum_via_merge_sort(ll *arr, ll left, ll right) {
    ll midpoint, inversion_count = 0;

    if (left < right) {
        midpoint = (left + right) / 2;

        inversion_count += merge_sort(arr, left, midpoint);
        inversion_count += merge_sort(arr, midpoint + 1, right);

        inversion_count += merge(arr, left, midpoint + 1, right);
    }

    return inversion_count;
}

int main() {
    ll size;

    scanf("%lld", &size);

    ll arr[size];

    for (ll i = 0; i < size; i++) {
        scanf("%lld", &arr[i]);
    }


    ll left = 0;
    ll right = size - 1;

    ll inversion_count = merge_sort(arr, left, right);

    printf("%lld\n", inversion_count);

    return 0;
}

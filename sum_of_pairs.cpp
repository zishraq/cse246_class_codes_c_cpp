#include <bits/stdc++.h>
using namespace std;


long long int count_pairs(long long int arr[], long long int n, long long int target)
{
    long long int count = 0;

    map <long long int, long long int> pair_count;

    for (long long int i = 0; i < n; i++) {
        if (arr[i] * 2 == target) {
            count += 1;
        }

        pair_count[arr[i]]++;
    }

    for (long long int i = 0; i < n; i++) {
        count += pair_count[target - arr[i]];

        if (target - arr[i] == arr[i]) {
            count--;
        }
    }

    return count;
}

int main()
{
    long long int n, x;

    cin >> n >> x;

    long long int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << count_pairs(arr, n, x) << endl;

    return 0;
}
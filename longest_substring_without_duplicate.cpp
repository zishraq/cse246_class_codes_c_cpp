#include <iostream>
using namespace std;

int longestSubstringWithoutDuplicateBruteForce(string str) {
    int hasAppeared[26];
    int max_length = 0;
    int length = 0;

    for (int i = 0; i < str.size(); i++) {
        length = 0;
        for (int j = 0; j < 26; j++) {
            hasAppeared[j] = 0;
        }

        for (int j = i; j < str.size(); j++) {
            if (hasAppeared[str[j] - 'a'] == 1) {
                if (length > max_length) {
                    max_length = length;
                }
                break;
            } else {
                length++;
                hasAppeared[str[j] - 'a'] = 1;
            }
        }

        if (length > max_length) {
            max_length = length;
        }
    }

    return max_length;
}

int longestSubstringWithoutDuplicateWithTwoPointers(string str) {

    int left = 0;
    int right = 1;

    int length = 1;
    int max_length = 1;

    int has_appeared[26] = {0};

    has_appeared[str[0] - 'a'] = 1;

    while (right < str.size()) {

        while (has_appeared[str[right] - 'a'] == 1) {
            has_appeared[str[left] - 'a'] = 0;
            left++;
            length--;
        }

        has_appeared[str[right] - 'a'] = 1;
        length++;

        if (length > max_length) {
            max_length = length;
        }

        right++;
    }

    return max_length;
}

int main() {
    string str = "abcjkjcbfgab";

    int substring_length = longestSubstringWithoutDuplicateWithTwoPointers(str);

    printf("%d\n", substring_length);

    return 0;
}
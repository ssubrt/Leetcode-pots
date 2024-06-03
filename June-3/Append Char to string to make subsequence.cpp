------------->>>>>>>>>>>>>>>>>>>>>> Approach <<<<<<<<<<<<<<<<<<<<<<<<<<--------------------------

    // Time complexity:O(n+m)

    // Space complexity:O(1)


class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0;  // Pointer for `s`
        int j = 0;  // Pointer for `t`

        // Traverse both strings
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                j++;  // Move to the next character in `t`
            }
            i++;  // Move to the next character in `s`
        }

        // The number of characters remaining in `t` that are not matched in `s`
        return t.length() - j;
    }
};

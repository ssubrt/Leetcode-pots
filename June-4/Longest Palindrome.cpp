-------------->>>>>>>>>>>>>>>>>> Approach <<<<<<<<<<<<<<<<<<<----------------------
//  T.c - O(n)
// S.C - O(1)


class Solution {
public:
    int longestPalindrome(string s) {
        // Step 1: Count the frequency of each character
        unordered_map<char, int> charCount;
        for (char c : s) {
            charCount[c]++;
        }
        
        // Step 2: Calculate the length of the longest palindrome
        int length = 0;
        bool hasOdd = false;
        
        for (const auto& entry : charCount) {
            int count = entry.second;
            if (count % 2 == 0) {
                // If the count is even, use all characters
                length += count;
            } else {
                // If the count is odd, use the largest even part
                length += count - 1;
                hasOdd = true;
            }
        }
        
        // Step 3: If there's any character with an odd count, add one to the length
        if (hasOdd) {
            length += 1;
        }
        
        return length;
    }
};
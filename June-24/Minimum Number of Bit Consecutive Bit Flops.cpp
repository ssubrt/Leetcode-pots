-------------------->>>>>>>>>>>>>>>>>>>>> Approach <<<<<<<<<<<<<<<<<<<<<<<<<<----------------------------
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
         int n = A.size();
    vector<int> flip(n + 1, 0);
    int flipCount = 0, result = 0;

    for (int i = 0; i < n; ++i) {
        flipCount ^= flip[i];
        if (A[i] == flipCount) {
            if (i + K > n) return -1;
            ++result;
            flipCount ^= 1;
            flip[i + K] ^= 1;
        }
    }

    return result;
    }
};
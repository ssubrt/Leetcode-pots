------------>>>>>>>>>>>>>>>> Approaches <<<<<<<<<<<<<<<<<<<<<<-------------

// T.C - O(n)
// S.c - O(n)

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
       
        int n = arr.size();
        for(int i =0;i<=n-3;i++){
            if((arr[i])%2 !=0 && (arr[i+1])%2 != 0 && (arr[i+2])%2 != 0)
            return true;
        }
        return false;
    }
};

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        // Loop through the array up to the third-to-last element
        for (int i = 0; i < n - 2; i++) {
            int product = arr[i] * arr[i + 1] * arr[i + 2];
            // Check if the product is odd
            if (product % 2 == 1) return true;
        }
        return false;
    }
};

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int window = 0;
        for (int i = 0; i < 3 && i < arr.size(); i++) {
            window += arr[i] % 2;
        }
        if (window == 3) {
            return true;
        }
        for (int i = 3; i < arr.size(); i++) {
            window += arr[i] % 2;
            window -= arr[i - 3] % 2;
            if (window == 3) {
                return true;
            }
        }
        return false;
    }
};
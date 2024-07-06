------------>>>>>>>>>>>> Approach <<<<<<<<<<<<<<------------------

// time complexity - O(n)
// space complexity - o(n)

class Solution {
public:
    int passThePillow(int n, int time) {
         // Initialize an array from 1 to n
        vector<int> arr;
        for(int i = 1; i <= n; i++) {
            arr.push_back(i);
        }

        // Variable to keep track of current position
        int currentIndex = 0;
        int direction = 1; // 1 means moving forward, -1 means moving backward

        // Simulate the passing of the pillow
        for(int i = 0; i < time; i++) {
            currentIndex += direction;
            if(currentIndex == n - 1 || currentIndex == 0) {
                direction *= -1; // Change direction at the ends
            }
        }

        // Return the final position (1-based index)
        return arr[currentIndex];
    }
};
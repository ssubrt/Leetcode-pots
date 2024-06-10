---------------------->>>>>>>>>>>>>>>>>> Approach -1 <<<<<<<<<<<<<<<<<<<<<<<<<<<<-----------------------
// T.C - O(NlogN)
// S.C - O(N)

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sortedHeights = heights; // Create a copy of the original heights
        sort(sortedHeights.begin(), sortedHeights.end()); // Sort the copy

        int count = 0; // Initialize count outside the loop

        // Compare the original heights with the sorted heights
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != sortedHeights[i]) {
                count++;
            }
        }

        return count;
    }
};



---------------------->>>>>>>>>>>>>>>>>> Approach -2 <<<<<<<<<<<<<<<<<<<<<<<<<<<<-----------------------

// T.C - O(N)
// S.C - O(N)

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        // Step 1: Find the maximum height to determine the range of our counting array
        int max_height = *max_element(heights.begin(), heights.end());
        
        // Step 2: Create a counting array
        vector<int> count(max_height + 1, 0);
        
        // Step 3: Count the frequencies of each height
        for (int height : heights) {
            count[height]++;
        }
        
        // Step 4: Reconstruct the sorted order using the counting array
        int index = 0;
        int mismatches = 0;
        for (int height = 0; height <= max_height; height++) {
            while (count[height] > 0) {
                if (heights[index] != height) {
                    mismatches++;
                }
                index++;
                count[height]--;
            }
        }
        
        return mismatches;
    }
};

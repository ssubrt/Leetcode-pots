--------------->>>>>>>>>>>>>>> Approach <<<<<<<<<<<<<<<<<<<<---------------------

// time complexity of this code is O(n * m)
// The space complexity is O(N)

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(); // row count
        int m = matrix[0].size(); // column count
        vector<int> ans; // to store lucky numbers

        for (int i = 0; i < n; i++) {
            int minRowValue = INT_MAX;
            int minColIndex = -1;
            
            // Find the minimum value in the row
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] < minRowValue) {
                    minRowValue = matrix[i][j];
                    minColIndex = j;
                }
            }
            
            // Check if this minimum value is the maximum in its column
            bool isLucky = true;
            for (int k = 0; k < n; k++) {
                if (matrix[k][minColIndex] > minRowValue) {
                    isLucky = false;
                    break;
                }
            }
            
            // If it is a lucky number, add to the result
            if (isLucky) {
                ans.push_back(minRowValue);
            }
        }

        return ans;
    }
};
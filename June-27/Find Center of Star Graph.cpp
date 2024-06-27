---------->>>>>>>>>>>>>>>>>>> Approach <<<<<<<<<<<<<<<<<<<<<------------------------

// time complexity of this code is O(n)
// space complexity of this code is O(n


class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
         unordered_map<int, int> count;
    
    // Count the occurrences of each node
    for (const auto& edge : edges) {
        count[edge[0]]++;
        count[edge[1]]++;
    }
    
    // Find the node with the maximum count
    int n = edges.size() + 1; // number of nodes in the star graph
    for (const auto& pair : count) {
        if (pair.second == n - 1) {
            return pair.first;
        }
    }
    
    return -1; // This line should never be reached for a valid star graph
    }
};
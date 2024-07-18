----------------->>>>>>>>>>>>>>>> Approach <<<<<<<<<<<<<<<<---------------------

// time complexity of this solution is O(n^2)
// The space complexity is O(N)



class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        return dfs(root, distance).second;
    }
    
    pair<vector<int>, int> dfs(TreeNode* root, int distance) {
        if (!root) return {{}, 0};  // No nodes and no pairs
        
        if (!root->left && !root->right) {
            return {{1}, 0};  // A single leaf node at distance 1
        }
        
        auto left = dfs(root->left, distance);
        auto right = dfs(root->right, distance);
        
        vector<int> depths;
        int pairs = left.second + right.second;
        
        for (int l : left.first) {
            for (int r : right.first) {
                if (l + r <= distance) {
                    pairs++;
                }
            }
        }
        
        for (int l : left.first) {
            depths.push_back(l + 1);
        }
        for (int r : right.first) {
            depths.push_back(r + 1);
        }
        
        return {depths, pairs};
    }
};

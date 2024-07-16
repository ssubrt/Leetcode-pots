-------------->>>>>>>>>>>> Approach -1 <<<<<<<<<<<<<<<<<<<<<<----------------
// the time complexity is O(N). 
// The space complexity is O(H)

    bool getPath(TreeNode* root, int value, string& path) {
        if (!root) return false;
        if (root->val == value) return true;
        
        path.push_back('L');
        if (getPath(root->left, value, path)) return true;
        path.pop_back();
        
        path.push_back('R');
        if (getPath(root->right, value, path)) return true;
        path.pop_back();
        
        return false;
    }
    
    TreeNode* findLCA(TreeNode* root, int p, int q) {
        if (!root || root->val == p || root->val == q) return root;
        TreeNode* left = findLCA(root->left, p, q);
        TreeNode* right = findLCA(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string pathToStart, pathToDest;
        
        getPath(root, startValue, pathToStart);
        getPath(root, destValue, pathToDest);
        
        // Find the LCA
        TreeNode* lca = findLCA(root, startValue, destValue);
        
        // Find the path to the LCA
        string pathToLCA;
        getPath(root, lca->val, pathToLCA);
        
        // Remove the LCA part from both paths
        string trimmedPathToStart = pathToStart.substr(pathToLCA.size());
        string trimmedPathToDest = pathToDest.substr(pathToLCA.size());
        
        // Replace all characters in trimmedPathToStart with 'U'
        string upMoves(trimmedPathToStart.size(), 'U');
        
        // Final directions
        string directions = upMoves + trimmedPathToDest;
        
        return directions;
    }


-------------->>>>>>>>>>>> Approach -2 <<<<<<<<<<<<<<<<<<<<<<----------------
// the time complexity is O(N). 
// The space complexity is O(H)

bool getPath(TreeNode* root, int value, string& path) {
        if (!root) return false;
        if (root->val == value) return true;
        
        path.push_back('L');
        if (getPath(root->left, value, path)) return true;
        path.pop_back();
        
        path.push_back('R');
        if (getPath(root->right, value, path)) return true;
        path.pop_back();
        
        return false;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string pathToStart, pathToDest;
        
        getPath(root, startValue, pathToStart);
        getPath(root, destValue, pathToDest);
        
        // Find the common prefix
        int i = 0;
        while (i < pathToStart.size() && i < pathToDest.size() && pathToStart[i] == pathToDest[i]) {
            i++;
        }
        
        // Number of steps up to the common ancestor
        string directions = string(pathToStart.size() - i, 'U');
        // Add the remaining path to the destination
        directions += pathToDest.substr(i);
        
        return directions;
    }

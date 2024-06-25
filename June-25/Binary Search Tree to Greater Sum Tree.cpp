--------------->>>>>>>>>>>>>>>> Approach <<<<<<<<<<<<<<<<<<<<<<-------------------

// Time Complexity - O(n)
// Space Complexity - O(n)


class Solution {
public:
    TreeNode* helper(TreeNode* root,int &sum){
        if(!root) return NULL;
        helper(root->right,sum);
        sum += root->val;
        root->val = sum;
        helper(root->left,sum);
        return root;
    }


    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        return helper(root,sum);
    }
};
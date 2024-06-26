---------------------->>>>>>>>>>>>>>>>>> Approach <<<<<<<<<<<<<<<<<<<<<<-----------------------

// Time Complexity - O(n)
// Space Complexity - O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     void inorder(TreeNode* root,vector<int>&ans){
        if(!root) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
     }

     TreeNode* inorderToBst(int start,int end,vector<int>&in){
        if(start>end) return NULL;
        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(in[mid]);
        root->left = inorderToBst(start,mid-1,in);
        root->right = inorderToBst(mid+1,end,in);
        return root;
     }


    TreeNode* balanceBST(TreeNode* root) {
        vector<int>in;
        inorder(root,in);
        return inorderToBst(0,in.size()-1,in);
    }
};
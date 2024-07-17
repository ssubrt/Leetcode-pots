------------>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Approach <<<<<<<<<<<<<<<<<<<<<<<<<<-------------------------

// time Complexity  - O(N)
// space complexity  - O(N+M)

class Solution {
public:
    vector<TreeNode*> forest;
    
     TreeNode* deleteNodes(TreeNode* root, unordered_set<int>& to_delete_set){
        if(!root) return NULL;

        root->left = deleteNodes(root->left,to_delete_set);
        root->right = deleteNodes(root->right,to_delete_set);

        if(to_delete_set.find(root->val) != to_delete_set.end()){
            if(root->left) forest.push_back(root->left);
            if(root->right) forest.push_back(root->right);
            delete root;
            return NULL;
         } 

         return root;
     }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
         unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
         if(deleteNodes(root,to_delete_set)){
            forest.push_back(root);
         }
         return forest;
    }
};

------------>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Approach-2 <<<<<<<<<<<<<<<<<<<<<<<<<<-------------------------

// time Complexity  - O(N)
// space complexity  - O(N)


class Solution {
public:
    vector<TreeNode*> forest;

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        if (!root) return {};

        stack<pair<TreeNode*, bool>> s;
        s.push({root, true});

        while (!s.empty()) {
            auto [node, is_root] = s.top();
            s.pop();

            if (!node) continue;

            bool to_delete = to_delete_set.find(node->val) != to_delete_set.end();
            if (is_root && !to_delete) {
                forest.push_back(node);
            }

            if (node->left) s.push({node->left, to_delete});
            if (node->right) s.push({node->right, to_delete});

            if (node->left && to_delete_set.find(node->left->val) != to_delete_set.end()) {
                node->left = nullptr;
            }

            if (node->right && to_delete_set.find(node->right->val) !=            to_delete_set.end()) {
                node->right = nullptr;
            }
        }

        return forest;
    }
};
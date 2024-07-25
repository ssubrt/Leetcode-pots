------------------->>>>>>>>>>>>>>>>> Approach <<<<<<<<<<<<<<<<<<<<<<<<<<<-----------------------
// Time complexity: O(n⋅logn)
// Space complexity: O(n)

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(nums[i]);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        for(auto &it:nums){
            ans.push_back(it);
        }
        return ans;
    }
};
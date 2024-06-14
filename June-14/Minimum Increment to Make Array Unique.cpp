------------------->>>>>>>>>>>>>>> Approach <<<<<<<<<<<<<<<<<<<<<<<<<------------------
// Time Complexity: O(nlog⁡n)
// Space Complexity: O(log⁡n)


class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        if(nums.empty())  return 0;
        sort(nums.begin(),nums.end());
        int n  = nums.size();
        int operation = 0 ; 
        int nextAvailable = nums[0];
        for(int i=0;i<n;i++){
            if(nums[i]<nextAvailable){
                operation += (nextAvailable-nums[i]);
                nextAvailable++;
            }
            else{
                nextAvailable = nums[i]+1;
            }
        }
        return operation;
    }
};


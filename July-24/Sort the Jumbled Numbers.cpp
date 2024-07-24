------------------->>>>>>>>>>>>>>>>> Approach <<<<<<<<<<<<<<<<<<<<<<<<<<<-----------------------
// Time complexity: O(n⋅logn)
// Space complexity: O(n)

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int > > storePairs;

        for(int i=0;i<nums.size();i++){
            string number = to_string(nums[i]);
            string formed = "";
            for(int j=0;j<number.size();j++){
                formed = formed + (to_string(mapping[number[j] -'0']));
            }

            // store the mapped value
            int mappedValue = stoi(formed);
            storePairs.push_back({mappedValue,i});
        } 

        sort(storePairs.begin(),storePairs.end());
        vector<int> ans;
        for(auto pair : storePairs){
            ans.push_back(nums[pair.second]);
        }
        return ans;
    }
};
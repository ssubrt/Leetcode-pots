-------------------->>>>>>>>>>>>>>>>>> Approach <<<<<<<<<<<<<<<<<<<<<<<<<<<<-----------------------


    //Time complexity:O(n)

    //Space complexity:O(min(n,k))

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;

        unordered_map<int, int> remainderIndexMap;
        remainderIndexMap[0] = -1; // Handle case where the subarray starts from the beginning

        int runningSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            runningSum += nums[i];
            int remainder = runningSum % k;

            // Adjust for negative remainders to handle negative numbers properly
            if (remainder < 0) remainder += k;

            if (remainderIndexMap.find(remainder) != remainderIndexMap.end()) {
                if (i - remainderIndexMap[remainder] > 1) {
                    return true;
                }
            } else {
                remainderIndexMap[remainder] = i;
            }
        }
        return false;
    }
};
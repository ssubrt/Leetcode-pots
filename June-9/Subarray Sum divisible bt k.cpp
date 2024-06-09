
---------------------->>>>>>>>>>>>>>>>>>>> Approach  <<<<<<<<<<<<<<<<<<<<<<<<--------------------

// time Complexity - O(n)
// Space Complexity - O(n)



class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        mpp[0]=1;
        int prefixSum = 0 ;
        int count =0;

        for(int num:nums){
            prefixSum += num;
            int remainder  = prefixSum % k;

             if(remainder <0){
            remainder += k;
        }

        if(mpp.find(remainder) != mpp.end()){
            count += mpp[remainder];
        }

           mpp[remainder]++;
        }

        return count;
    }


};
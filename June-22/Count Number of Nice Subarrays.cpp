------------------>>>>>>>>>>>>>>>>>>>>> Approach <<<<<<<<<<<<<<<<<<<<<<<<---------------------------

//  time complexity of this code is O(n)
//  space complexity of this code is O(n)

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        countMap[0] = 1;  // Initialize with count 0 occurring once
        int oddCount = 0;
        int result = 0;
        
        for (int num : nums) {
            // Increase oddCount if the number is odd
            if (num % 2 != 0) {
                oddCount++;
            }
            // If there are (oddCount - k) subarrays ending before the current element,
            // it means there are some subarrays ending at the current element that 
            // have exactly k odd numbers.
            if (countMap.find(oddCount - k) != countMap.end()) {
                result += countMap[oddCount - k];
            }
            // Update the count of subarrays with oddCount odd numbers
            countMap[oddCount]++;
        }
        
        return result;
    }
};

------------------------->>>>>>>>>>>>>>>>>> Approach-2 <<<<<<<<<<<<<<<<<<<<<<<<<<<<----------------------

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {

public:

    

    int helpMe(vector<int>& nums, int goal){



      

        int l=0; int r=0; int sum =0; int cnt =0;



        if(goal<0) return 0;





        while(r<nums.size()){

            sum += nums[r]%2;



            while(sum>goal){

                sum =sum - nums[l]%2;

                l++;

            }

            cnt = cnt + (r-l+1);

            r=r+1;

        }

        return cnt;

     }

    int numberOfSubarrays(vector<int>& nums, int k) {

         return helpMe(nums,k) - helpMe(nums,k-1);

    }

};

----------->>>>>>>>>>>>>>>>> Approach<<<<<<<<<<<<<<<<<<-----------------

// T.C - O(n log n)
// S.C - O(log n)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    }
};



--------------------->>>>>>>>>>>>>>>>> Approach <<<<<<<<<<<<<<<<<----------------------

// T.C - O(n)
// S.C - O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n= nums.size();
        int zeros = 0; int ones = 0; int twos = 0 ;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zeros++;
            }
            else if(nums[i]==1){
                ones++;
            }
            else{
                twos++;
            }
        }

        int i=0;
        while(zeros--){
            nums[i]=0;
            i++;
        }
        while(ones--){
            nums[i]=1;
            i++;
        }
        while(twos--){
            nums[i]=2;
            i++;
        }
    }
};




-------------------->>>>>>>>>>>>>>>> Approach <<<<<<<<<<<<<<<<<<<--------------------------------

// T.C - O(n )
// S.C - O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
      int l = 0;
      int h = nums.size()-1;
      int m = 0;
      while(m<=h){
        if(nums[m]==0){
          swap(nums[l],nums[m]);
          l++;
          m++;
        }
        else if(nums[m]==1){
          m++;
        }
        else{
          swap(nums[h],nums[m]);
            h--;
          }
        }
      }

        
  
};
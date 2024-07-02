------------->>>>>>>>>>>>>>>>>>> Approaches <<<<<<<<<<<<<<<<<---------------------

// Time Complexity :  O(n×m)

// Space Complexity : O(k)

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n = nums1.size(); 
        int m = nums2.size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(nums1[i] == nums2[j]){
                    ans.push_back(nums1[i]);
                    // Mark this element as used by setting it to a special value
                    // This avoids counting the same element multiple times
                    nums2[j] = INT_MIN; 
                    break; // Move to the next element in nums1
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;

        for(int num:nums1){
            auto it = find(nums2.begin(),nums2.end(),num);
            if(it != nums2.end()){
                 ans.push_back(num);
                nums2.erase(it); // Remove the found element to avoid duplicates
            }
        }
        return ans;
    }
};


---------------->>>>>>>>>>>>> Optimised <<<<<<<<<<<<<<<<<<-----------

// Time Complexity : O(n+k)
// Space Complexity : O(n+k)

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
         unordered_map<int, int> count;
        vector<int> ans;

        // Count elements in nums1
        for (int num : nums1) {
            count[num]++;
        }

        // Find intersections with nums2
        for (int num : nums2) {
            if (count[num] > 0) {
                ans.push_back(num);
                count[num]--;
            }
        }

        return ans;
    }
};
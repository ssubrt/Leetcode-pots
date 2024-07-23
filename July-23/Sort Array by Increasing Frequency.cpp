------------------>>>>>>>>>>>>>>>> Approach <<<<<<<<<<<<<<<<----------------------
// time complexity of the code is O(n + m log m)
// space complexity of the code is O(m + n)


class Solution {
public:
    
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        vector<pair<int, int>> freqPairs;
        for (const auto& pair : freqMap) {
            freqPairs.push_back(pair);
        }

        sort(freqPairs.begin(), freqPairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return (a.second == b.second) ? a.first > b.first : a.second < b.second;
        });

        vector<int> ans;
        for (const auto& pair : freqPairs) {
            ans.insert(ans.end(), pair.second, pair.first);
        }

        return ans;
    }
};
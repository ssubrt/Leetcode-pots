-------------->>>>>>>>>>>>>>>>>>> Approach <<<<<<<<<<<<<<<<<<<----------------------

// T.C - O(N*M)
//S.C - O(1)

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> minFreq;
        
        // Initialize minFreq using the first word
        for (char c : words[0]) {
            minFreq[c]++;
        }
        
        // Iterate through each subsequent word
        for (int i = 1; i < words.size(); ++i) {
            unordered_map<char, int> charFreq;
            for (char c : words[i]) {
                charFreq[c]++;
            }
            
            // Update the minFreq map with the minimum frequency
            for (auto& [key, val] : minFreq) {
                if (charFreq.count(key)) {
                    minFreq[key] = min(minFreq[key], charFreq[key]);
                } else {
                    minFreq[key] = 0;
                }
            }
        }
        
        // Collect the common characters
        vector<string> ans;
        for (auto& [key, val] : minFreq) {
            while (val > 0) {
                ans.push_back(string(1, key));
                val--;
            }
        }
        
        return ans;
    }
};

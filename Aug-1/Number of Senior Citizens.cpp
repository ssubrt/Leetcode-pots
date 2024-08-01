--------------------->>>>>>>>>>>>>>>>> Aprroach <<<<<<<<<<<<<<<<<-----------------------

// time complexity of this code is O(n)
// space complexity of this code is O(1)


class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size();
        int ans = 0; 

        for(int i=0;i<n;i++){
            string value  = details[i].substr(11,2);
            int age = stoi(value);
            if(age > 60){
                ans++;
            }
        }
        return ans;
    }
};
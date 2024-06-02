------------->>>>>>>>>>>>>>>> Approach-1 <<<<<<<<<<<<<<<<<<<------------------------
//  time complexity of this code is O(n),
//  The space complexity of this code is O(n) 


class Solution {
public:
    int scoreOfString(string& s, int i=1) {
        return (i==s.size())?0:abs(s[i]-s[i-1])+scoreOfString(s, i+1);
    }
};






------------------>>>>>>>>>>>>>>>>>> Approach-2 <<<<<<<<<<<<<<<<<<<<<<------------------------

//  time complexity of this code is O(1),
//  The space complexity of this code is O(1)

class Solution {
public:
    int scoreOfString(string& s, int i=1) {
        return (i==s.size())?0:abs(s[i]-s[i-1])+scoreOfString(s, i+1);
    }
};



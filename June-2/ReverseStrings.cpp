----------------------->>>>>>>>>>>>>>>>> Approach - 1 <<<<<<<<<<<<<<<<<<<<<<--------------------------
//The time complexity of this code is O(n)
// The space complexity of this code is O(1)



class Solution {
public:
    void reverseString(vector<char>& s) {
      int start =0;
    int end = s.size()-1;
    while(start<=end){
        swap(s[start++],s[end--]);
    }
        
    }
};


--------------------------->>>>>>>>>>>>>>>>> Approach - 2 <<<<<<<<<<<<<<<<<<<<<<--------------------------
//The time complexity of this code is O(n)
// The space complexity of this code is O(n)

class Solution {
public:
    void reverse(vector<char> &s,int left,int right){
        if(left >= right) return;

        swap(s[left],s[right]);
        reverse(s,left+1,right-1);
    }
    void reverseString(vector<char>& s) {
        reverse(s,0,s.size()-1);
    }
};



------------------>>>>>>>>>>>>>>>>>>>> Approach -3   <<<<<<<<<<<<<<<<<<<<<<<<<<<-------------------------
//The time complexity of this code is O(n)
// The space complexity of this code is O(1)

class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};

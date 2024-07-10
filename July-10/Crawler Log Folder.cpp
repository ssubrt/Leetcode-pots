---------------->>>>>>>>>>>>>>>>>>> Approach -1 <<<<<<<<<<<<<<<<<<<<<<<-----------------------

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution {
public:
    int minOperations(vector<string>& logs) {
         stack<string> st;
    
    for (const string& log : logs) {
        if (log == "../") {
            if (!st.empty()) {
                st.pop();
            }
        } else if (log != "./") {
            st.push(log);
        }
    }
    
    return st.size();
    }
};

---------------->>>>>>>>>>>>>>>>>>> Approach -2 <<<<<<<<<<<<<<<<<<<<<<<-----------------------

// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
    
    for (const string& log : logs) {
        if (log == "../") {
            if (depth > 0) {
                depth--;
            }
        } else if (log != "./") {
            depth++;
        }
    }
    
    return depth;
    }
};
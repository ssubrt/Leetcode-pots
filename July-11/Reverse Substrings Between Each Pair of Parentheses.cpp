-------------->>>>>>>>>>>>> Approach <<<<<<<<<<<<<<<-------------------------

// Time Complexity - O(n)
// Space COmplexity - O(n)

class Solution {
public:
    string reverseParentheses(string s) {
    stack<string> st;
    string curr;

    for (char c : s) {
        if (c == '(') {
            st.push(curr);
            curr = "";
        } else if (c == ')') {
            reverse(curr.begin(), curr.end());
            if (!st.empty()) {
                curr = st.top() + curr;
                st.pop();
            }
        } else {
            curr += c;
        }
    }

    return curr;
    }
};
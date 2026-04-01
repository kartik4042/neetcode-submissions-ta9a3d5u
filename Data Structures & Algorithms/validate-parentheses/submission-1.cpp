class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> mpp = {{'(',')'}, {'[',']'}, {'{','}'}};
        stack<char> st;

        for(char ch : s)
        {
            if(!st.empty() && mpp[st.top()] == ch)
            {
                st.pop();
                continue;
            }
            st.push(ch);
        }
        return st.empty();
    }
};

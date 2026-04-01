class Solution {
public:
    vector<string> generateParenthesis(int n) {
        stack<tuple<string, int, int>> st;
        vector<string> result;

        st.push({"", 0, 0});
        while(!st.empty())
        {
            auto[current, open, close] = st.top();
            st.pop();

            if(current.size() == 2*n)
                result.push_back(current);

            if(open < n)
                st.push({current + '(', open + 1, close});

            if(close < open)
                st.push({current + ')', open, close + 1});
        }
        return result;
    }
};

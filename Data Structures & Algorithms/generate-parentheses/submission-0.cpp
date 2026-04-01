class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string path;
        backtrack(0, 0, n, path, result);
        return result;
    }

private:
    void backtrack(int open, int close, int n, string& path, vector<string>& result)
    {
        if(open == close && open == n)
        {
            result.push_back(path);
            return;
        }

        if(open < n)
        {
            path += '(';
            backtrack(open + 1, close, n, path, result);
            path.pop_back();
        }

        if(close < open)
        {
            path += ')';
            backtrack(open, close + 1, n, path, result);
            path.pop_back();
        }
    }
};

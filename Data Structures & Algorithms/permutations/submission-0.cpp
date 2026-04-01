class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> result;
        vector<bool> seen(nums.size(), false);
        backtrack(nums, path, result, seen);
        return result;
    }

private:
    void backtrack(vector<int>& nums, vector<int>& path, vector<vector<int>>& result, vector<bool>& seen)
    {
        if(nums.size() == path.size())
        {
            result.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(seen[i]) continue;
            
            seen[i] = true;
            path.push_back(nums[i]);
            backtrack(nums, path, result, seen);
            path.pop_back();
            seen[i] = false;
        }
    }
};

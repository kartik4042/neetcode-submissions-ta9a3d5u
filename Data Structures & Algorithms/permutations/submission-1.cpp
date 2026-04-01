class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<int> path;
        vector<vector<int>> result;
        vector<bool> seen(nums.size(), false);
        dfs(nums, path, result, seen);
        return result;    
    }

    void dfs(vector<int>& nums, vector<int>& path, vector<vector<int>>& result, vector<bool>& seen)
    {

        if(nums.size() == path.size())
        {
            result.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(seen[nums[i]]) continue;
            seen[nums[i]] = true;
            path.push_back(nums[i]);
            dfs(nums, path, result, seen);
            path.pop_back();
            seen[nums[i]] = false;
        }
    }
};

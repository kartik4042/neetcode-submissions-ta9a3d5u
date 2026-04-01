class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> result;
        vector<int> path;
        dfs(0, nums, result, path, target);
        return result;    
    }

    void dfs(int index, vector<int>& nums, vector<vector<int>>& result, vector<int>& path, int target)
    {
        if(target == 0)
        {
            result.push_back(path);
            return;
        }

        if(target < 0)
            return;

        for(int i = index; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            dfs(i, nums, result, path, target - nums[i]);
            path.pop_back();
        }
    }
};

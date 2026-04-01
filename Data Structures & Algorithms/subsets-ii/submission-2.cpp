class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> path;
        dfs(0, nums, path, result);
        return result;    
    }

    void dfs(int index, vector<int>& nums, vector<int>& path, vector<vector<int>>& result)
    {
        result.push_back(path);

        for(int i = index; i < nums.size(); i++)
        {
            if(i > index && nums[i] == nums[i - 1]) continue;

            path.push_back(nums[i]);
            dfs(i+1, nums, path, result);
            path.pop_back();
        }
    }
};

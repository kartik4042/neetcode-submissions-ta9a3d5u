class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> result;
        vector<int> path;
        int n = nums.size();
        vector<bool> visited(n, false);
        dfs(nums, result, path, visited);
        return result;    
    }

    void dfs(vector<int>& nums, vector<vector<int>>& result, vector<int>& path, vector<bool>& visited)
    {
        if(path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(visited[i]) continue;

            visited[i] = true;
            path.push_back(nums[i]);
            dfs(nums, result, path, visited);
            path.pop_back();
            visited[i] = false;
        }
    }
};

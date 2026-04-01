class Solution
{
    public:
        vector<vector<int>> combinationSum(vector<int>& nums, int target)
        {
            vector<vector<int>> result;
            vector<int> path;
            dfs(0, nums, path, result, target);
            return result;
        }

        void dfs(int index, vector<int>& nums, vector<int>& path, vector<vector<int>>& result, int target)
        {
            if( target == 0)
            {
                result.push_back(path);
                return;
            }

            if(target < 0)
                return;

            for(int i = index; i < nums.size(); i++)
            {

                path.push_back(nums[i]);
                dfs(i, nums, path, result, target - nums[i]);
                path.pop_back();
            }
        }
};
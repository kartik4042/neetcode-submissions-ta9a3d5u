class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> path;
        vector<vector<int>> result;
        backtrack(0, nums, path, result, target);
        return result;
    }

private:
    void backtrack(int index, vector<int>& nums, vector<int>& path, vector<vector<int>>& result, int target)
    {
        if(target == 0)
        {
            result.push_back(path);
            return;
        }

        for(int i = index; i < nums.size(); i++)
        {
            if(nums[i] > target) continue;

            path.push_back(nums[i]);
            backtrack(i, nums, path, result, target - nums[i]);
            path.pop_back();
        }
    }
};

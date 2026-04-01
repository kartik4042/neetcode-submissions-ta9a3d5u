class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> path;
        vector<vector<int>> result;
        backtrack(0, nums, path, result);
        return result;
    }

private:
    void backtrack(int index, vector<int>& nums, vector<int>& path, vector<vector<int>>& result)
    {
        result.push_back(path);

        for(int i = index; i < nums.size(); i++)
        {
            if(i > index && nums[i] == nums[i - 1]) continue;

            path.push_back(nums[i]);
            backtrack(i + 1, nums, path, result);
            path.pop_back();
        }
    }
};

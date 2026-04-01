class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> path;
        dfs(0, candidates, result, path, target);
        return result;    
    }

    void dfs(int index, vector<int>& candidates, vector<vector<int>>& result, vector<int>& path, int target)
    {
        if(target == 0)
        {
            result.push_back(path);
            return;
        }

        if(target < 0)
            return;

        for(int i = index; i < candidates.size(); i++)
        {
            if(i > index && candidates[i] == candidates[i - 1]) continue;
            path.push_back(candidates[i]);
            dfs(i + 1, candidates, result, path, target - candidates[i]);
            path.pop_back();
        }
    }
};

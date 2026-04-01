class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       sort(candidates.begin(), candidates.end());
        vector<int> path;
        vector<vector<int>> result;
        backtrack(0, candidates, target, path, result);
        return result;
    }

private:
    void backtrack(int index, vector<int>& candidates, int target, vector<int>& path, vector<vector<int>>& result)
    {
        //base condition (either a check, or result of some arithematic operation)
        if(target == 0)
        {
            result.push_back(path);
            return;
        }

        if(target < 0)
            return;

        for(int i  = index; i < candidates.size(); i++)
        {
            //skip duplicates
            if(i > index && candidates[i] == candidates[ i - 1]) continue;

            //pruning
            if(candidates[i] > target) continue;

            //inclusion
            path.push_back(candidates[i]);

            //recursion call
            backtrack(i + 1, candidates, target - candidates[i], path, result);

            //exclusion (restore state)
            path.pop_back();
        }
    }
};

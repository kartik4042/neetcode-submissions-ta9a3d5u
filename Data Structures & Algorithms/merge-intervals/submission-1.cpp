class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        int n = intervals.size();
        result.push_back(intervals[0]);

        for(auto& interval : intervals)
        {
            int start = interval[0];
            int end = interval[1];
            int lastEnd = result.back()[1];
            
            if(start <= lastEnd)
            {
                result.back()[1] = max(end, lastEnd);
            }
            else
            {
                result.push_back(interval);
            }
        }    
        return result;
    }
};

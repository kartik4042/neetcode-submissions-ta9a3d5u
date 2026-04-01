class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     unordered_map<int, int> freq;
     for(int num : nums)
     {
        freq[num]++;
     }   

        vector<vector<int>> arr(nums.size() + 1);
        for(auto &it : freq)
        {
            arr[it.second].push_back(it.first);
        }

        vector<int> result;
        for(int i = arr.size() - 1; i > 0; i--)
        {
            for(int n : arr[i])
            {
                result.push_back(n);
                if(result.size() == k)
                    return result;
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.empty()) return {};
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> result;

        for(int i = 0; i < n; i++)
        {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = n - 1;

            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum < 0)
                {
                    left++;
                }
                else if(sum > 0)
                {
                    right--;
                }
                else
                {
                    result.push_back({nums[i], nums[left], nums[right]});

                    int leftVal = nums[left];
                    int rightVal = nums[right];

                    while(left < right && nums[left] == leftVal) left++;
                    while(left < right && nums[right] == rightVal) right--;
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int prev2 = 0;
        int prev1 = 0;

        for(int num : nums)
        {
            int pick = num + prev2;
            int notpick = prev1;

            int curr = max(pick, notpick);

            prev2 = prev1;
            prev1 = curr;
        }  
        return prev1;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mpp;
        int left = 0, result = 0;

        for(int right = 0; right < s.size(); right++)
        {
            if(mpp.find(s[right]) != mpp.end())
            {
                left = max(left, mpp[s[right]] + 1);
            }
            mpp[s[right]] = right;
            result = max(result, right - left + 1);
        }
        return result;
    }
};

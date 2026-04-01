class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int left = 0, result = 0;

        for(int right = 0; right < s.size(); right++)
        {
            if(mp.find(s[right]) != mp.end())
            {
                left = max(mp[s[right]] + 1, left);
            }

            mp[s[right]] = right;
            result = max(result, right - left + 1);
        }
        return result;
    }
};

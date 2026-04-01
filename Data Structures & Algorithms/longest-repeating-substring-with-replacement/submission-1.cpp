class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        unordered_map<char, int> seen;
        int left = 0;
        int length = 0;
        int maxFreq = 0;
        for(int right = 0; right < s.size(); right++)
        {
            seen[s[right]]++;
            maxFreq = max(maxFreq, seen[s[right]]);
            if((right - left + 1) - maxFreq > k)
            {
                seen[s[left]]--;
                left++;
            }
            length = max(length, right - left + 1);
        }    
        return length;
    }
};

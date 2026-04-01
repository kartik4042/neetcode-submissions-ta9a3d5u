class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        unordered_map<char, int> mpp;
        for(int i = 0; i < s.size(); i++)
            mpp[s[i]] = i;

        int size = 0;
        int end = 0;
        vector<int> result;

        for(int i = 0; i < s.size(); i++)
        {
            size++;
            end = max(end, mpp[s[i]]);

            if(end == i)
            {
                result.push_back(size);
                size = 0;
            }
        }
        return result;    
    }
};

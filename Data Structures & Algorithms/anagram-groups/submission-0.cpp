class Solution
{
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs)
        {
            unordered_map<string, vector<string>> group;
            for(string &str : strs)
            {
                vector<int> freq(26, 0);
                for(char &ch : str)
                    freq[ch - 'a']++;

                string key = to_string(freq[0]);
                for(int i = 1; i < 26; i++)
                {
                    key += '#' + to_string(freq[i]);
                }

                group[key].push_back(str);
            }

            vector<vector<string>> result;
            for(auto &it : group)
            {
                result.push_back(it.second);
            }

            return result;
        }
};
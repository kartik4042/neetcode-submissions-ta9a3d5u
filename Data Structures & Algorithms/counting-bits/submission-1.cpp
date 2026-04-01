class Solution {
public:
    vector<int> countBits(int n) 
    {
        vector<int> res;
        for(int i = 0; i <= n; i++)
            res.push_back(hammingWeight(i));
        return res;    
    }

    int hammingWeight(int n)
    {
        int res = 0;
        while(n != 0)
        {
            n &= (n - 1);
            res++;
        }
        return res;
    }
};

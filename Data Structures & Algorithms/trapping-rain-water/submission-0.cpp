class Solution {
public:
    int trap(vector<int>& height) {
     if(height.empty())
        return 0;

        int l = 0, r = height.size() - 1;
        int lmax= height[l], rmax = height[r];
        int result = 0;
        while( l < r )
        {
            if(lmax < rmax)
            {
                l++;
                lmax = max(lmax, height[l]);
                result += lmax - height[l];
            }
            else
            {
                r--;
                rmax = max(rmax, height[r]);
                result += rmax - height[r];
            }
        }   
        return result;
    }
};

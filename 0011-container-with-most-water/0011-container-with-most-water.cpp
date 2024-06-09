class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int start = 0,end = height.size()-1;
        int ans = 0;
        while(start<=end)
        {
            ans = max(min(height[start],height[end])*(end-start),ans);
            height[start] > height[end] ? end-- : start++;
        }    
        return ans;
    }
};
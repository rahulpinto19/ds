class Solution {
public:
    int maxWidthRamp(vector<int>& nums) 
    {
        stack<int>s;
        int res = 0;
        for(int i=0;i<nums.size();i++)
        if(s.empty() || nums[s.top()] > nums[i])
            s.push(i);

        for(int i= nums.size()-1;i>res;i--)
        {
            while(s.size() and nums[s.top()] <= nums[i])
            res = max(res,i-s.top()),s.pop();
        }       
        return res;
    }
};
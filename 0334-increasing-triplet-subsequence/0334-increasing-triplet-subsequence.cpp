class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        // int n = nums.size();
        // vector<int>l,r;
        // l.push_back(nums[0]);
        // r.push_back(nums[n-1]);

        // for(int i = 1;i<n;i++)
        //     l.push_back(min(l.back(),nums[i]));
        // for(int i = n-2;i>=0;i--)
        //     r.push_back(max(r.back(),nums[i]));
        // reverse(r.begin(),r.end());

        // for(int i = 0;i<n;i++)
        // {
        //     if(l[i] < nums[i] and nums[i] < r[i])
        //         return 1;
        // }
        // return 0;

        int first = INT_MAX;
        int second = INT_MAX;

        for(auto x:nums)
        {
            if(first >= x) first = x;
            else if(second >= x ) second = x;
            else return true;  
        }
        return false;
    }
};
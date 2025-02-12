class Solution {
public:
    int conv(int number)
    {
        int res = 0;
        while(number)
        {
            res+=number%10;
            number/=10;
        }
        return res;
    }
    int maximumSum(vector<int>& nums) 
    {
        int ans = -1;
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;    

        for(auto x:nums)
        {
            if(mp.find(conv(x)) != mp.end())
            {
                ans = max(ans,x + mp[conv(x)]);
            }
            mp[conv(x)] = x;
        }
        return ans;
    }
};
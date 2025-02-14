class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int ans1 = -1,ans2 = -1,cnt1 = 0,cnt2 = 0;
        for(auto x:nums)
        {
            if(ans1 == x)
                cnt1++;
            else if (ans2 == x)
                cnt2++;
            else if(cnt1 == 0)
                {ans1 = x;cnt1 =1;}
            else if(cnt2 == 0)
                {ans2 = x;cnt2 = 1;}
            else
                {cnt1--;cnt2--;}
        }    
        cnt1 = 0;cnt2 = 0;
        for(auto x:nums)
        {
            if(ans1 == x)
                cnt1++;
            else if(ans2  == x)
                cnt2++;
        }
        vector<int>ans;
        if(cnt1 > nums.size()/3) ans.push_back(ans1);
        if(cnt2 > nums.size()/3) ans.push_back(ans2);
        return ans;

    }
};
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        //    int num1=-1,num2=-1,count1=0,count2=0;
    int n1 = -1,n2 = -1,cnt1 = 0,cnt2 = 0;
        for(auto x:nums)
        {
            if(x == n1)    cnt1++;
            
            else if(x == n2) cnt2++;

            else if(cnt1 == 0)
            {
                n1 = x;
                cnt1 = 1;
            }
            else if(cnt2 == 0)
            {
                n2 = x;
                cnt2 = 1;
            }
            else
            {
                cnt1 --;
                cnt2--;
            }
        }
        cnt1=0,cnt2=0;
        for(auto x:nums)
        {
            if(n1 ==x)
            cnt1++;
            else if (n2 ==x)
            cnt2++;
        }
        vector<int>ans;
        if(cnt1> nums.size()/3)
            ans.push_back(n1);
        if(cnt2>nums.size()/3)
            ans.push_back(n2);
        return ans;
    }
};

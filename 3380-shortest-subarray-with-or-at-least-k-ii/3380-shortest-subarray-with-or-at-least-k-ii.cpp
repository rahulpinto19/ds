class Solution {
public:
    void set(int val,vector<int>&bits)
    {
        for(int i=0;i<32;i++)
        {
            if(((1<<i) & val))
            bits[i]++;
        }
    }
    void unset(int val,vector<int>&bits)
    {
        for(int i=0;i<32;i++)
        {
            if((1<<i) & val)
            bits[i]-=1;
        }
    }
    int count(vector<int>bits)
    {
       int val = 0;
       for(int i=0;i<32;i++)
       {
            if(bits[i])
            val|=(1<<i);
       }
    //    cout<<val<<endl;
       return val;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) 
    {
        int start = 0;
        
        int ans = INT_MAX;
        vector<int>bits(32,0);
        for(int end =0;end<nums.size();end++)
        {
                set(nums[end],bits);
            while(start <= end and count(bits) >=k )
            {
                ans = min(ans,end-start+1);
                unset(nums[start],bits);
                start++;
            }
        }    
        return ans == INT_MAX ? -1: ans ;
    }
};
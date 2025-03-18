

class Solution {
public:
    bool check(int number,vector<int>&bits)
    {
        int pos = 0;
        while(number)
        {
            int bit = number%2;
            if(bit + bits[pos] >=2)
                return 0;
            pos++;
            number/=2;
        }
        return 1;
    }
    void remove(int number,vector<int>&bits)
    {
        int pos = 0;
        while(number)
        {
            int bit = number%2;
            bits[pos]-=bit;
            pos++;
            number/=2;
        }
    }
    void add(int number,vector<int>&bits)
    {
        int pos = 0;
        while(number)
        {
            int bit = number%2;
            bits[pos]+=bit;
            pos++;
            number/=2;
        }
    }
    int longestNiceSubarray(vector<int>& nums) 
    {
        vector<int>bits(32,0);
        int ans = 1;
        int end = 0;
        for(int i = 0 ;i<nums.size();i++)
        {
            while(end<i and !check(nums[i],bits))
            {
                remove(nums[end],bits);
                end++;
            }
            add(nums[i],bits);
            ans = max(ans,i - end + 1);
        }
        return ans;
    }
};
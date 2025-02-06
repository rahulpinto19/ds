class Solution {
public:
    int tupleSameProduct(vector<int>& nums) 
    {
        int ans = 0;
        unordered_map<int,int>mp;
        for(int i = 0;i<nums.size();i++)
        {
            for(int j = i+1;j<nums.size();j++)
            {
                int prod = nums[i]*nums[j];
                ans+= (mp.find(prod) != mp.end()) ? mp[prod]*8 : 0;
                mp[prod]++; 
            }
        }    
        return ans;
    }
};
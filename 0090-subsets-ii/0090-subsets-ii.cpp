class Solution {
public:
    vector<vector<int>>ans;
    void help(vector<int>&nums,int pos,vector<int>temp)
    {
        ans.push_back(temp);

        for(int ind = pos;ind<nums.size();ind++)
        {
            if(ind!=pos and nums[ind] == nums[ind-1]) continue;
            temp.push_back(nums[ind]);
            help(nums,ind+1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        help(nums,0,temp);    
        return ans;
    }
};
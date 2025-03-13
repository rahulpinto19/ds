class Solution {
public:
    bool help(vector<int>& nums, vector<vector<int>>& queries,int ind)
    {
        int n = nums.size();
        vector<long long>temp(n+1,0);
        for(int i = 0;i<=ind;i++)
        {
            vector<int>x = queries[i];
            temp[x[0]] += -x[2];
            temp[x[1] + 1] += x[2]; 
        }    

        for(int i = 1;i<=n;i++)
        {
            temp[i] += temp[i-1];
        }
        for(int i = 0;i<n;i++)
        {
            if(temp[i] + nums[i] > 0)
                return 0;
        }
        return 1;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int start = 0,end = queries.size()-1;
        int ans = -1;
        
        int flag = 0;
        for(auto x:nums)
        {
            if(x>0)
                {flag = 1;break;}
        }
        if(!flag)
            return 0;
        while(start<=end)
        {
            int mid = start + ( end - start)/2;
            if(help(nums,queries,mid))
            {
                ans = mid;
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        if(ans == -1)
            return ans;
        return ans+1;
    }
};
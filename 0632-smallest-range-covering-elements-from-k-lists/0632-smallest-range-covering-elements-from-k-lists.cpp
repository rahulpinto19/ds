class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) 
    {
        vector<pair<int,int>>ord;
        for(int k =0;k<nums.size();k++)
            for(int x:nums[k])
            ord.push_back({x,k});

        sort(begin(ord),end(ord));

        int i=0,k=0;
        vector<int>ans;
        unordered_map<int,int>count;

        for(int j=0;j<ord.size();j++)
        {
            if(! count[ord[j].second]++) ++k;
            if(k == nums.size())
            {
                while(count[ord[i].second]>1) --count[ord[i++].second];
                 if (ans.empty() || ans[1] - ans[0] > ord[j].first - ord[i].first) {
                    ans = vector<int>{ord[i].first, ord[j].first};
                }
            }
        }
        return ans;
    }
};
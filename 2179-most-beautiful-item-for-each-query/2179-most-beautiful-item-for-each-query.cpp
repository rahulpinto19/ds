bool comp(vector<int>&a,vector<int>&b)
{
    if(a[0] == b[0])
    return a[1] < b[1];

    return a[0] < b[0];
}
class Solution {
public:
   int lastOccurance(vector<vector<int>>&v,int target)
{
        int start = 0,end = v.size()-1;
        int ans = -1;
        while(start<=end)
        {
            int mid = (start + end)/2;
            if(v[mid][0]<= target)
                {ans = mid;
                start = mid + 1;}
            else
                end = mid-1;
        }
        return ans;
}
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) 
    {
        vector<int>temp;
        sort(items.begin(),items.end(),comp);    
        int val = INT_MIN;
        for(auto x:items)
        {
            val = max(val,x[1]);
            temp.push_back(val);
        }
        vector<int>ans;
        for(auto x:queries)
        {
            int ind = lastOccurance(items,x);
            if(ind == -1)
            ans.push_back(0);
            else
            ans.push_back(temp[ind]);
        }
       
        return ans;
    }
};
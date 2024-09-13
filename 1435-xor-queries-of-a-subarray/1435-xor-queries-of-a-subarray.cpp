class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) 
    {
        arr.insert(arr.begin(),0);
        for(int i=1;i<arr.size();i++)
        {
            arr[i]  = arr[i-1]^arr[i];
        }
        vector<int>ans;
        for(auto x:queries)
        {
            ans.push_back(arr[x[0]] ^ arr[x[1]+1]);
        }
        return ans;
    }
};
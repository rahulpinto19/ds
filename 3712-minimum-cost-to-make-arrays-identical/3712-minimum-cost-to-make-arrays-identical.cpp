class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) 
    {
        int n = arr.size();
        long long ans1 = 0,ans2 = 0;
        vector<int>n1,n2;
        for(int i=0;i<n;i++)
        {
            ans1+=abs(arr[i]-brr[i]);
        }
        n1 = arr;
        n2 = brr;

        sort(n1.begin(),n1.end());
        sort(n2.begin(),n2.end());

        for(int i=0;i<n;i++)
        {
            ans2+=abs(n1[i]-n2[i]);
        }
        return min(ans1,ans2 + k);
    }
};
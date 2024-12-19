class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) 
    {
        int curr = 0,sum = 0,ans=0;
        for(int i = 0;i<arr.size();i++)
        {
            curr+=i;
            sum+=arr[i];
            ans +=(curr == sum);
        }
        return ans;
    }
};
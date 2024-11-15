class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) 
    {
        int j  = arr.size()-1;
        while(j>0 and arr[j]>=arr[j-1])j--;
        if(!j)
        return 0;
        int ans =  j;
        for(int i=0;i<j and  (i==0 or arr[i-1]<=arr[i]);i)
        {
            while( j<arr.size() and arr[i] > arr[j])
            j++;
            ans = min(ans,j-i-1);
            i++;
        }
        return ans == 0 ? -1  : ans;
    }
};
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) 
    {
        long long sum = 0;
        int minVal = INT_MAX;
        int cnt = 0;
        for(auto x:matrix)
        {
            for(auto val:x)
            {
                if(val<0)
                cnt++;
                sum+=abs(val);
                minVal = min(minVal,abs(val));
            }
        }
        return cnt%2 ? sum - 2*minVal : sum;
    }
};
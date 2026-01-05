class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {

        long long res = 0;
        int neg = 0,zero = 0;
        int minValue = INT_MAX;
        for(auto x:matrix) {
            for(auto y:x) {
                if(y< 0) {

                    neg++;
                }
                minValue = min(minValue,abs(y));
                if(y == 0) zero++;
                res += abs(y);
            }
        }      
        cout<<minValue;
        if(neg%2 == 0 || zero) {
            // cout<<res;
            return res;
        }

        return res - 2*minValue;
    }
};

class Solution {
public:
     int merge(vector<vector<int>>& A) 
      {
        
        int res = 0;
            sort(A.begin(), A.end());
            int pre = A[0][1];
            for (auto& ab : A) 
            {
                int a = ab[0], b = ab[1];
                res += pre <= a;
                pre = max(pre, b);
            }
            return res > 1;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> Horizontal, Vertical;
        for (auto x : rectangles) {
            Horizontal.push_back({min(x[0], x[2]), max(x[0], x[2])});
            Vertical.push_back({min(x[1], x[3]), max(x[1], x[3])});
        }
        return merge(Horizontal) || merge(Vertical) ;
    }
};
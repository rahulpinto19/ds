class Solution {
public:
    int help(vector<int>v) {
        
        int n = v.size();
        vector<int>v1(n,0),v2(n,0);
        stack<int>s1,s2;

        for(int i = 0;i<v.size();i++) {

            while(s1.size() and v[s1.top()] >= v[i])
                s1.pop();
            v1[i] = s1.empty() ? 0 : s1.top() + 1;
            s1.push(i);
        }
        for(int i = v.size()-1;i>=0;i--) {

            while(s2.size() and v[s2.top()] >= v[i])
                s2.pop();
            v2[i] = s2.empty() ? v.size()-1 : s2.top() - 1;
            s2.push(i);
        }
        int ans = 0;
        for(int i = 0;i<v.size();i++) {
            ans = max(ans,v[i] * (v2[i] - v1[i] + 1));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        vector<vector<int>>mat;
        for(auto x:matrix) {
            vector<int>temp;
            for(auto y:x) {
                temp.push_back( y == '0' ? 0 : 1);
            }
            mat.push_back(temp);
        }
        // vector<int>
        for(int i = 1;i<mat.size();i++) {
            for(int j = 0;j<mat[0].size();j++) {

                if(mat[i][j])
                mat[i][j] += mat[i-1][j];
            }
        }

        int ans = 0;
        for(auto x:mat) {
            ans = max(ans,help(x));
        }
        return ans;
    }
};
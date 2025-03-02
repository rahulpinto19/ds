class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& n1,
                                    vector<vector<int>>& n2) {
        vector<vector<int>> ans;
        int i = 0, j = 0;
        while (i < n1.size() and j < n2.size()) {
            if (n1[i][0] < n2[j][0]) {
                if (ans.size() and ans.back()[0] == n1[i][0]) {
                    ans.back()[1] += n1[i][1];
                } else
                    ans.push_back(n1[i]);
                i++;
            } else {
                if (ans.size() and ans.back()[0] == n2[j][0]) {
                    ans.back()[1] += n2[j][1];
                } else
                    ans.push_back(n2[j]);
                j++;
            }
        }

        while (i < n1.size()) {
            if (ans.size() and ans.back()[0] == n1[i][0]) {
                ans.back()[1] += n1[i][1];
            }

            else
                ans.push_back(n1[i]);
            i++;
        }
        while (j < n2.size()) {
            if (ans.size() and ans.back()[0] == n2[j][0]) {
                ans.back()[1] += n2[j][1];
            } else
                ans.push_back(n2[j]);
            j++;
        }
        return ans;
    }
};
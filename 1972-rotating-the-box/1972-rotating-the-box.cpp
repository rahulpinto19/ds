class Solution {
public:
    char getval(int val) {
        if (val == 0)
            return '.';
        else if (val == 2)
            return '*';
        else
            return '#';
        
    }
    vector<vector<char>> rotate90Right(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<char>> rotated(n, vector<char>(m));

        // Fill the new matrix by rotating 90 degrees clockwise
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rotated[j][m - i - 1] = getval(matrix[i][j]);
            }
        }
        return rotated;
        
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        vector<vector<int>> ans(box.size());
        // vector<vector<char>>ans(box[0].size());

        for (int i = 0; i < box.size(); i++) {
            vector<int> temp;
            for (int j = box[0].size() - 1; j >= 0; j--) {
                if (box[i][j] == '*') {
                    sort(temp.begin(), temp.end());
                    temp.insert(temp.begin(), 2);
                    ans[i].insert(ans[i].begin(), temp.begin(), temp.end());
                    temp = {};
                } else if (box[i][j] == '.')
                    temp.push_back(0);
                else
                    temp.push_back(1);
            }
            if (temp.size()) {
                sort(temp.begin(), temp.end());
                ans[i].insert(ans[i].begin(), temp.begin(), temp.end());
            }
        }
        return rotate90Right(ans);
;
        
    }
};
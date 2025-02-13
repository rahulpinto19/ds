class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int flag = 1;
        for (int i = 0; i < mat.size(); i++) {
            if (mat[i][0] == 0)
                flag = 0;
            for (int j = 1; j < mat[0].size(); j++) {
                if (mat[i][j] == 0)
                    mat[i][0] = mat[0][j] = 0;
            }
        }
        for (auto x : mat) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }
        cout<<endl<<flag;
        for (int i = mat.size() - 1; i >= 0; i--) {
            for (int j = mat[0].size() - 1; j >= 1; j--) {
                if(mat[i][0] == 0 || mat[0][j] == 0)
                    mat[i][j] = 0;
            }
        if(flag == 0) mat[i][0] = 0;
        }
    }
};
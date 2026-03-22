class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {

            for(int r = 0;r<4;r++) {

                vector<vector<int>>cur;
                for(int j = 0;j<mat[0].size();j++) {
                    vector<int>temp;
                    for(int i = 0;i<mat.size();i++) {
                        temp.push_back(mat[i][j]);
                    }
                    reverse(temp.begin(),temp.end());
                    cur.push_back(temp);
                }
                mat = cur;
                if(mat == target) return true;
            }        
            return false;
    }
};

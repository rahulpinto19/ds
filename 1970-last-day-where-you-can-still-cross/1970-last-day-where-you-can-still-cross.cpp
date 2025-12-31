class Solution {
public:

    bool help(vector<vector<int>>&cells,int &ind,int row,int col) {
        
        // vector<vector<int>>v;
        vector<vector<int>>v(row,vector<int>(col,0));
        queue<pair<int,int>>q;
        int dir[] = {-1,0,1,0,-1};

        for(int i = 0;i<ind;i++) {

            v[cells[i][0]-1][cells[i][1]-1] = 1;
        }
       

        for(int i = 0;i<col;i++) {
            
            if(v[0][i] == 0) {
                v[0][i] = 1;
                q.push({0,i});
            }
        }
        
        while(!q.empty()) {
            
                auto cur = q.front();
                q.pop();
                if(cur.first == v.size()-1) {
                    return 1;
                }
                v[cur.first][cur.second] = 1;

              
                for(int i = 0;i<4;i++) {

                    int nx = cur.first + dir[i];
                    int ny = cur.second + dir[i+1];

                    if(nx < 0 || nx >= v.size() || ny< 0 || ny >= v[0].size() || v[nx][ny])
                        continue;
                    q.push({nx,ny});   
                    v[nx][ny] = 1; 
                }

        }

        return 0;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        // vector<vector<int>>v(row,vector<int>(col,0));

        int low = 0,high = cells.size()-1;

        int res = 0;
        while(low <= high) {

            int mid = low + (high - low) / 2;

            bool flag = help(cells,mid,row,col);
            if(flag) {

                res = mid;
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }

        return res;
    }
};
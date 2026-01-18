class Solution {
public:
    int help(vector<vector<int>>&grid,int i,int j,int mxSide) {

        int inc = 0;
        int res = 0;
        while(i+inc < grid.size() and j+inc<grid[0].size()) {

            int x1 = i,y1 = j;
            int x2 = i+inc,y2 = j + inc;

            set<int>st;

            for(int x = x1;x<=x2;x++) {
                int cur = 0;
                for(int y = y1;y<=y2;y++) {
                    cur+=grid[x][y];
                }
                st.insert(cur);
            }
            for(int y = y1;y<=y2;y++) {
                int cur = 0;
                for(int x = x1;x<=x2;x++) {
                    cur+=grid[x][y];
                }
                st.insert(cur);
            }

            int k = inc;

            int cur1 = 0,cur2 = 0;
            
            for(int x = 0;x<=k;x++) {
                cur1+= grid[i+x][j+x];
            }
            
            for(int x = 0;x<=k;x++) {
                cur2 += grid[i+x][y2-x];
            }
            
            st.insert(cur1);
            st.insert(cur2);
            
            if(st.size() == 1 and !inc) {

                cout<<i<<":"<<j<<endl;
                cout<<cur1<<" "<<cur2<<endl;
            }


            if(st.size() == 1) res = max(res,inc);
            inc++;

        }
        return res + 1;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        
        int ans = 0;
        int m = grid.size(),n = grid[0].size();

        int mxSide = min(m,n);

        for(int i = 0;i<grid.size();i++) {
            for(int j = 0 ;j<grid[0].size();j++) {

                ans = max(help(grid,i,j,mxSide),ans);
            }
        }
        return ans;
    }
};
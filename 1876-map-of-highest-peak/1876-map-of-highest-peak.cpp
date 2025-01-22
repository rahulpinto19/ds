class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& w) 
    {
        queue<pair<int,int>>q;
        
        for(int i = 0;i<w.size();i++)
        {
            for(int j = 0;j<w[0].size();j++)
            {
                w[i][j] = w[i][j] == 1 ? 0 : -1;

                if(w[i][j] == 0) q.push({i,j});
            }
        }
        int h = 1;
        int dir[5] = {-1,0,1,0,-1};
        while(q.size())
        {
            int size = q.size();

            while(size--)
            {
                int i = q.front().first,j = q.front().second;
                
                q.pop();
                for(int k=0;k<4;k++)
                {
                    int x = i + dir[k] , y = j + dir[k+1];
                    if(x>=0 and x<w.size() and y>=0 and y < w[0].size() and w[x][y] == -1)
                    {
                        w[x][y] = h;
                        q.push({x,y});
                    }
                }
            }
            h++;
        }
        return w;
    }   
};
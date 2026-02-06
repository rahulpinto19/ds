#define v vector<int>
class Solution {
public:
    struct comp {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        return a[0] > b[0]; // Min-heap usually requires '>'
        }
    };
    int minimumObstacles(vector<vector<int>>& grid) {
        
        int n = grid.size(),m = grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        priority_queue<v,vector<v>,comp>pq;

        pq.push({grid[0][0],0,0});

        vector<int>dir = {-1,0,1,0,-1};
        while(!pq.empty()) {


            auto cur = pq.top();
            pq.pop();
            int x = cur[1],y = cur[2];
            
            if(x == n-1 and y == m-1) return cur[0];
            if(vis[x][y]) continue;
            
            vis[x][y] = 1;

            for(int i = 1;i<=4;i++) {

                int nx = x + dir[i-1];
                int ny = y + dir[i];

                if(nx<0 or nx>=n or ny<0 or ny>=m or vis[nx][ny])
                    continue;
                pq.push({cur[0]+grid[nx][ny],x+dir[i-1],y+dir[i]});
            }
        }
        return 0;
    }
};
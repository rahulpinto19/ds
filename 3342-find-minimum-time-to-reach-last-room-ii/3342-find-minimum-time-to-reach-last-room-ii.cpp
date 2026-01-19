class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
         int n = moveTime.size(),m = moveTime[0].size();

        vector<vector<int>>nextMove(n,vector<int>(m,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;

        pq.push({0,0,0,2});
        moveTime[0][0] = 0;

        vector<int>dir = {-1,0,1,0,-1};
        while(!pq.empty()) {

            auto cur = pq.top();
            pq.pop();

            int curTime = cur[0];
            int cRow = cur[1];
            int cCol = cur[2];
            int whatTake = cur[3] == 1 ? 2 : 1;

            if(curTime >= nextMove[cRow][cCol]) continue;
            if(cRow == n-1 and cCol == m-1) return curTime;

            nextMove[cRow][cCol] = curTime; 
            for(int i = 0;i<4;i++) {

                int nx = cRow + dir[i];
                int ny = cCol + dir[i+1];

                if(nx>=0 and nx<n and ny>=0 and ny<m and nextMove[nx][ny] == INT_MAX) {
                    int c = max(curTime,moveTime[nx][ny]) + whatTake;

                    pq.push({c,nx,ny,whatTake});
                }
            }

        }
        return -1;
    }
    
};
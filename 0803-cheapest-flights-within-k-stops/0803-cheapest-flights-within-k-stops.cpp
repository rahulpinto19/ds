class Solution
{
public:
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
    {        
        unordered_map<int,vector<pair<int,int>>>adj;

        for(auto x:flights)
        {
            int u = x[0];
            int v = x[1];
            int wt = x[2];
            adj[u].push_back({v,wt});
        }
        // {flights , {node,dist}}
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});

        vector<int>dis(n,1e9);
        dis[src] = 0;
        while(q.size())
        {
            auto x = q.front();
            q.pop();
            int f = x.first;
            int node = x.second.first;
            int cost = x.second.second;
            if(f>K) continue;
            for(auto it : adj[node])
            {
                int adjNode = it.first;
                int endW = it.second;
                if(cost + endW < dis[adjNode] and f<=K)
                {
                    dis[adjNode] = cost + endW;
                    q.push({f+1,{adjNode,cost + endW}});
                }
            }
        }
        if(dis[dst] == 1e9) return -1;
        return dis[dst];
    }
};

/*
 vector<vector<int>> dp(K+2, vector<int>(n, INT_MAX));
        
        //dp[i][j] = Dist to reach j using atmost i edges from src
        
        for(int i = 0; i <= K+1; i++)
        {
            dp[i][src] = 0; // Dist to reach src always zero
        }
        
        for(int i = 1; i <= K+1; i++)
        {
            for(auto &f: flights)
            {
                //Using indegree
                int u = f[0];
                int v = f[1];
                int w = f[2];
                
                if(dp[i-1][u] != INT_MAX)
                    dp[i][v] = min(dp[i][v], dp[i-1][u] + w);
            }
        }
        
        return (dp[K+1][dst] == INT_MAX)? -1: dp[K+1][dst];
*/ 
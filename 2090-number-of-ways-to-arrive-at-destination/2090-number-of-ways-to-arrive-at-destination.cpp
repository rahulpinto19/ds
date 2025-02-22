class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        vector<vector<pair<int,int>>>adj(n);
        vector<long long>dist(n,LONG_MAX);
        vector<int>paths(n,0);
        dist[0] = 0;
        paths[0] = 1;
        for(auto x:roads)
        {
            int u = x[0];
            int v = x[1];
            int wt = x[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;

        pq.push({0,0});
        int mod = 1e9 + 7;

        while(!pq.empty())
        {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it:adj[node])
            {
                long long adjNode = it.first;
                long long edw = it.second;

                if(dis + edw < dist[adjNode])
                {
                    dist[adjNode] = dis + edw;
                    paths[adjNode] =  paths[node] %mod;
                    pq.push({dist[adjNode], adjNode});

                }
                else if (dis + edw == dist[adjNode])
                {
                    paths[adjNode]= (paths[adjNode] + paths[node] )%mod;
                }
            }
        }
        return paths[n-1] % mod;
    }
};
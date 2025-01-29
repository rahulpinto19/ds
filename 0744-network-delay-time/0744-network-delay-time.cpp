class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto time:times)
        {
            int u = time[0];
            int v = time[1];
            int wt = time[2];

            adj[u].push_back({v,wt});
        }
        vector<int>res(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        res[k] = 0;

       pq.push({0,k});
       while(pq.size())
       {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto &vec:adj[node])
            {
                int adjNode = vec.first;
                int dist = vec.second;

                if(d + dist < res[adjNode])
                {
                    res[adjNode] = d + dist;
                    pq.push({d + dist, adjNode});
                }
            }
       }
       int ans = INT_MIN;
       for(int i =1;i<=n;i++)
       ans = max(ans,res[i]);

       if(ans == INT_MAX) return -1;

       return ans;
    }
};
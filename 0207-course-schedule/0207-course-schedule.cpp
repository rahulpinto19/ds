class Solution {
public:
    bool isCyclic(int V, vector<vector<int>> adj) 
    {
        int cnt = 0;
        vector<int>indegree(V,0);
        for(int i = 0;i<V;i++)
        {
            for(auto node:adj[i])
                indegree[node]++;
        }
        queue<int>q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i] == 0) q.push(i);
        }
        
        while(q.size())
        {
            int node = q.front();
            q.pop();
            cnt++;
            for(auto neighbour:adj[node])
            {
                indegree[neighbour]--;
                if(indegree[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
        }
        return !(cnt == V);
    }
    bool canFinish(int n, vector<vector<int>>& p) 
    {
        
        vector<vector<int>>adj(n+1);
        for(auto x:p)
        {
            adj[x[0]].push_back(x[1]);
        }
        return !(isCyclic(n,adj));    
    }
};
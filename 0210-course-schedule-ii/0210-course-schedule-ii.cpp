class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, stack<int>& s,
             vector<int>& vis) {
        if (vis[node])
            return;
        vis[node] = 1;
        for (auto neighbor : adj[node]) {
            dfs(neighbor, adj, s, vis);
        }
        s.push(node);
        return;
    }
    bool isCycle(int n, vector<vector<int>> adjlist) {
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {

            for (auto neighbor : adjlist[i])
                indegree[neighbor]++;
        }
        int cnt = 0;
        queue<int> q;
        for (int i = 0; i < n; i++) {

            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (q.size()) {
            int node = q.front();
            q.pop();
            cnt++;
            for (auto neighbor : adjlist[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        return !(cnt == n);
    }
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> vis(n, 0);
        vector<vector<int>> adj(n);
        vector<int> ans;
        for (auto x : p) {
            adj[x[1]].push_back(x[0]);
        }
        bool cycle = isCycle(n,adj);
        if(cycle)
            return {};
        stack<int> s;
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                dfs(i, adj, s, vis);
        }
        cout << "";
        while (s.size()) {
            ans.push_back(s.top());
            s.pop();
        }
        
        if(ans.size() == n)
        {
            
            return ans;
        } 
        return {};
    }
};

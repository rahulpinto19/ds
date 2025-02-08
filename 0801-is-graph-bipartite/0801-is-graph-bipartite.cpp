class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        queue<int> q;
        for (int i = 0; i < n; i++) 
        {
            if(color[i] != -1)
                continue;
            color[i] = 0;
            q.push(i);
            while (q.size()) {
                int node = q.front();
                q.pop();
                for (auto it : graph[node]) {
                    if (color[it] == -1) {
                        {
                            color[it] = !color[node];
                            q.push(it);
                        }
                    } else if (color[it] == color[node])
                        return false;
                }
            }
        }

        return true;
    }
};
class Solution {
public:
    bool dfs(int node,vector<vector<int>>&graph,vector<int>&color)
    {
        bool a = true;
        for(auto neighbor:graph[node])
        {
            if(color[neighbor] == color[node])
                return false;
            else if(color[neighbor] == -1)
            {
                color[neighbor] = !color[node];
                a&=dfs(neighbor,graph,color);
            }
        }
        return a;
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i =0;i<n;i++)
        {
            if(color[i] != -1)
                continue;
            color[i] = 0;
            if(!dfs(i,graph,color))
                return false;
        }    
        return true;
    }
};

/*
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
1*/ 
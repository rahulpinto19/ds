class Solution {
public:
    void bfs(vector<int>&indegree,unordered_map<int,vector<int>>g,int root)
    {
        for(auto x:g[root])
        {
            indegree[x]--;
            if(indegree[x] <=0)
                bfs(indegree,g,x);
        }
        return ;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        unordered_map<int,vector<int>>g;
        int v = graph.size();
        vector<int>indegree(v,0),safenodes;

        for(int i = 0;i<graph.size();i++)
        {
            for(auto neighbour:graph[i])
            {
                g[neighbour].push_back(i);
                indegree[i]++;
            }
        }  
        queue<int>q;
       
        for(int i =0;i<v;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while(q.size())
        {
            int node = q.front();
            q.pop();
            safenodes.push_back(node);
            for(auto x:g[node])
            {
                indegree[x]--;
                if(indegree[x] == 0)
                    q.push(x);
            }
        }
        sort(safenodes.begin(),safenodes.end());
        return safenodes;
    }
};
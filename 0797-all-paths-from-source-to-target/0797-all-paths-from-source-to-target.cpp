class Solution {
public:
    unordered_map<int,vector<int>>adj;
    vector<vector<int>>ans;
    unordered_map<int,int>vis;
    void help(int node,int dest,vector<int>&cur) {

        if(node == dest) {
            cur.push_back(node);
            ans.push_back(cur);
            cur.pop_back();
            return;
        }
        if(vis[node]) return;

        vis[node] = 1;
        for(auto x:adj[node]) {
            if(!vis[x]) {
                cur.push_back(node);
                help(x,dest,cur);
                cur.pop_back();
            }
        }
        vis[node] = 0;
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        for(int i = 0;i<graph.size();i++) {

            for(auto x:graph[i]) {
                adj[i].push_back(x);
            }
        }
        vector<int>cur;
        help(0,graph.size()-1,cur);

        return ans;
    }
};
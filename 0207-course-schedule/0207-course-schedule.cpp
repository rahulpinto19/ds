class Solution {
public:
    vector<vector<int>>adj;
    int v = 0;
    bool isCylce() {

        vector<int>indegree(v,0);
        for(auto x:adj) {
            for(auto nbr:x) {
                indegree[nbr]++;
            }
        }
        int edge = 0;
        queue<int>q;
        for(int i = 0;i<v;i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {

            auto node = q.front();q.pop();
            edge++;
            for(auto nbr:adj[node]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }
        return !(v==edge);
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        v = numCourses;
        adj.resize(v);    
        for(auto x:prerequisites) {
            adj[x[0]].push_back(x[1]);
        }
        return !isCylce();
    }
};
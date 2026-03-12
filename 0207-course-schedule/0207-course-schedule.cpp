class Solution {
public:
    vector<vector<int>>adj;
    bool isCyclic(int v) {

        vector<int>indegree(v,0);
        for(auto x:adj){
            for(auto nbr:x) {
                indegree[nbr]++;
            }
        }

        queue<int>q;
        for(int i = 0;i<v;i++) {
            if(indegree[i] == 0)q.push(i);
        }
        int edge = 0;
        while(!q.empty()) {

            auto curr = q.front();q.pop();
            edge++;
            for(auto nbr:adj[curr]) {
                
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }

        }
        return !(v==edge);
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.resize(numCourses);

        for(auto x:prerequisites) {
            adj[x[0]].push_back(x[1]);
        }
        return !isCyclic(numCourses);
    }
};
class DisjointSetUnion
{

    vector<int>parent,rank;
    public:
    DisjointSetUnion(int n ) 
    {
        rank.resize(n+1);
        for(int i =0;i<n+1;i++)
	    parent.push_back(i);
    }
    int findUparent(int node) 
    {
		if(parent[node] == node) return node;
			
		return parent[node] = findUparent( parent[node]);
    }
    void unionByrank(int u,int v) 
    {

        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);
    
        if(ulp_u == ulp_v) return;

        if(rank[ulp_u]  <  rank[ulp_v])parent[ulp_u] = ulp_v; 	

        else if (rank[ulp_u]  >  rank[ulp_v]) parent[ulp_v] = ulp_u; 	
        
        else 
        {
	        parent[ulp_v] = ulp_u;
	        rank[ulp_u]++;
        }

    }

};

class Solution {
public:
    
    vector<int> findRedundantConnection(vector<vector<int>>& adj) {
        
        DisjointSetUnion ds(adj.size());
        vector<int>ans;
       for(auto x:adj)
       {
           if(ds.findUparent(x[0]) == ds.findUparent(x[1])) {return x;}
           ds.unionByrank(x[0],x[1]);
       }
       return ans;
    }
};
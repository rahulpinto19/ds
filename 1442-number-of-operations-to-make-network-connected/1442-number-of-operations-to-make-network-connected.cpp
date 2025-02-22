
class DisjointSetUnion
{
    public:
    vector<int>parent,rank;
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
    
        if(ulp_u == ulp_v) { return;}

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
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        int exCables = 0;
        DisjointSetUnion d(n);
        for(auto x:connections)
        {
            if(d.findUparent(x[0]) == d.findUparent(x[1]))
            {
                exCables++;
            }
            else
            {
                d.unionByrank(x[0],x[1]);
            }
        }
        
        int cntC = 0;
        for(int i = 0;i<n;i++)
        {
            if(d.parent[i] == i) cntC++;
        }
        
        int ans = cntC - 1;
        if(exCables >= ans)
            return ans;
        return -1;
    }
};
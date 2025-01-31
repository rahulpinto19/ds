class DisjointsetUnion
{
    public:
    vector<int>parent,rank,size;
    DisjointsetUnion(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1);
        size.resize(n+1,1);

        for(int i=0;i<n+1;i++)
        parent[i] = i;
    }
    int findUltimateParent(int node)
    {
        if(parent[node] == node)
            return node;
        return parent[node] = findUltimateParent(parent[node]);
    }
    void unionByrank(int u,int v)
    {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);

        if(ulp_u == ulp_v) return ;

        if(rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }

    }
     void unionBySize(int u, int v) {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);

        if (ulp_u == ulp_v) return;  // Already in the same component

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];  // Merge u into v
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];  // Merge v into u
        }
    }
};

class Solution {
public:
    int m,n;
    bool isValid(int x,int y)
    {
        return x>=0 and y>=0 and x<m and y<n;
    }
    int largestIsland(vector<vector<int>>& grid) 
    {
        int mx = 0;
        m = grid.size();
        n = grid[0].size();
        DisjointsetUnion ds(m*n);
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j] == 0) continue;

                int dir[5] = {-1,0,1,0,-1};
                for(int d=0;d<4;d++)
                {
                    int nx = i + dir[d];
                    int ny = j + dir[d+1];
                    if(isValid(nx,ny) and grid[nx][ny])
                    {
                        int currNode = (i*n) + j;
                        int adjNode  = (nx*n) + ny;
                        ds.unionBySize(currNode,adjNode);
                    }
                }
               
            }
        }
         for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {

                if(grid[i][j] == 1) continue;
                int dir[5] = {-1,0,1,0,-1};
                set<int>components;
                
                 for(int d=0;d<4;d++) {
                    int nx = i + dir[d];
                    int ny = j + dir[d+1];
                    if(isValid(nx,ny) and grid[nx][ny]) {
                        int currNode = (i*n) + j;
                        int adjNode  = (nx*n) + ny;
                        components.insert(ds.findUltimateParent(adjNode));
                        }
                }
                int sizeTotal = 1;
                for(auto it:components) {
                    sizeTotal+= ds.size[it];
                }
                mx = max(mx,sizeTotal);
            }
        }
        for(int i = 0;i<m*n;i++)
            mx = max(mx,ds.size[ds.findUltimateParent(i)]);
        return mx;
    }
};
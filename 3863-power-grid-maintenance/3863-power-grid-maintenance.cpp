class DSU {
    public:
    vector<int>parent;
    DSU(int size) {
       parent.resize(size);
        for (int i = 0; i < size; ++i) {
            parent[i] = i; // Crucial: Each element is its own parent initially
        }
    }

    int find(int x) {
        if(x == parent[x]) return x;

        return parent[x] = find(parent[x]);
    }

    void join(int x,int y) {
        parent[find(x)] = find(y);
    }
};
class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        
        DSU dsu(c+1);

        for(auto x:connections) {
            dsu.join(x[0],x[1]);
        }
        
        vector<set<int>>comp(c+1);

        for(int i = 1;i<=c;i++) {
            comp[dsu.find(i)].insert(i);
        }
        vector<int>ans;

        for(auto x:queries) {
            const int task = x[0] ,node = x[1] , parent = (dsu.find(node));
            auto &curr = comp[parent];

            if(task ==  2) {
                curr.erase(node);
            }
            else {
                if(curr.empty()) ans.push_back(-1);
                else if(curr.count(node) ) ans.push_back(node);
                else ans.push_back(*curr.begin());
            }
        }

        return ans;
    }
};
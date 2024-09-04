class Solution {
public:
    // Custom hash function for std::pair<int, int>
    struct pair_hash 
    {
        template <class T1, class T2>
        std::size_t operator() (const std::pair<T1, T2>& p) const 
        {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            return h1 ^ (h2 << 1);  // XOR and bit shift to combine hashes
        }
    };
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) 
    {
        std::unordered_map<std::pair<int, int>, int, pair_hash> mp;
        for(auto x:obstacles)
        {
            mp[{x[0],x[1]}] = 1;
        }
        vector<vector<int>>dir = {{0,1},{1,0},{0,-1},{-1,0}};
        int ind = 0;
        int ans = 0;
        vector<int>curr = {0,0};
        for(auto x:commands)
        {
            int move = x;
            if(x == -1 || x== -2)
            {
                ind+=4;
                ind += (x == -1 ) ? 1 : -1;
                ind%=4;
                cout<<ind<<endl;
                continue;
            }
            while(move--)
            {
                if(mp.find({curr[0] + dir[ind][0],curr[1] + dir[ind][1]}) != mp.end())
                {
                    break;
                }
                curr[0]+=dir[ind][0];
                curr[1]+=dir[ind][1];

                ans = max(ans,curr[0]*curr[0] + curr[1]*curr[1]);
            }
        }
        return ans;
    }
};
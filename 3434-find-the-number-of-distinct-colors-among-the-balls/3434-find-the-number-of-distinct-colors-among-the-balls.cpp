class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) 
    {
        unordered_map<int,int>mp1;
        unordered_map<int,set<int>>mp2;
        vector<int>ans;
        for(auto x:queries)
        {
            int ball = x[0];
            int color = x[1];
            if(mp1.find(ball) != mp1.end())
            {
                mp2[mp1[ball]].erase(ball);
                if(mp2[mp1[ball]].size() == 0)
                    mp2.erase(mp1[ball]);
                mp1[ball] = color;
                mp2[color].insert(ball);
            }
            else
            {
                mp1[ball] = color;
                mp2[color].insert(ball);
            }
            ans.push_back(mp2.size());
        }
        return ans;
    }
};



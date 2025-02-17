class Solution {
public:
    set<string>s;
    void help(string tiles,int pos,vector<int>&used,string temp)
    {
        s.insert(temp);
        for(int i = 0;i<tiles.size();i++)
        {
            if(!used[i])
            {
                used[i] = 1;
                help(tiles,i+1,used,temp + tiles[i]);
                used[i] = 0;
            }
        }
        return;
    }
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        vector<int>used(n,0);
        help(tiles,0,used,"");
        return s.size()-1;
    }
};
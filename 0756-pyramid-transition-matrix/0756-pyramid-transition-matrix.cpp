class Solution {
public:
    unordered_map<string,vector<int>>mp;
    unordered_set<string>memo;
    bool solve(string bottom) {

        if(bottom.size() == 2) {
            return (mp.find(bottom) != mp.end());
        }

        if(memo.count(bottom)) return false;

        if(buildNextRow(bottom,"",0)) {
            return true;
        }
       
       memo.insert(bottom);

       return false;
    }
    bool buildNextRow(string cur,string next,int ind) {

        if(ind == cur.size()-1) {
            return solve(next);
        }

        string key = cur.substr(ind,2);

        if(mp.find(key) == mp.end())  return false;

        for(char val : mp[key]) {

            next.push_back(val);
            if(buildNextRow(cur,next,ind+1)) 
                return true;
            next.pop_back(); 
        }
        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        
        for(auto x:allowed) {
            string str = x.substr(0,2);
            mp[str].push_back(x[2]);
        }

        return solve(bottom);
    }
};
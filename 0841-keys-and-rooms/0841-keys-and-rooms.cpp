class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        queue<int>q;
        // set<int>s;
        unordered_map<int,int>mp;
        q.push(0);
        // s.insert(cur);
        mp[0] = 1;

        while(!q.empty()) {

            auto cur = q.front();
            q.pop();

            for(auto next : rooms[cur]) {

                if(mp[next]) continue;
                q.push(next);
                mp[next] = 1;
            }
        }
        return mp.size() == rooms.size();
    }
};
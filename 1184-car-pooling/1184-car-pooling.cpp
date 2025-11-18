class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        vector<int>v(1002,0);

        for(auto x:trips) {
            
            if(x[0] > capacity) return false;
            v[x[1]] += x[0];
            v[x[2]] += -x[0];
        }

        for(int i = 1;i<v.size();i++) {

            v[i]+=v[i-1];

            if(v[i] > capacity) return false;
        }
        return true;
    }
};
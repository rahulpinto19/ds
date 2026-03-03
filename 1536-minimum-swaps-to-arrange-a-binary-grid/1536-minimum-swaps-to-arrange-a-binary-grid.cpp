class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        
        // unordered_map<int,int>mp;
        vector<int>v;
        for(int i =0;i<grid.size();i++) {
            int cnt = 0;
            for(int j = grid[0].size()-1; j>=0 ;j--) {
                if(grid[i][j] == 0) {
                    cnt++;
                } else {
                    break;
                }
            }
            v.push_back(cnt);
        }
        int ans = 0;
        int req = grid[0].size()-1;
        for(int i = 0 ;i<v.size();i++) {

            int found = -1;
            for(int j = i;j<v.size();j++) {
                if(req<=v[j]) {
                    ans+= (j-i);
                    found =j;
                    break;
                }
            }
            if(found == -1) return -1;
            while(found > i) {
                swap(v[found],v[found-1]);
                found--;
            }
            req--;
        }

        return ans;
    }
};
// 3,0,3,3
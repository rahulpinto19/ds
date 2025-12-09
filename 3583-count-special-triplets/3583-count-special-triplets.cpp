class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        
        int M = 1e9 + 7;
        int n = nums.size();
        unordered_map<int,int>freqPrev,freqNext;

        vector<pair<int,int>>curr(n);
        curr[0] = {0,0};
        curr[n-1] = {0,0};
        
        long long res = 0;
        
        freqPrev[nums[0]]++;
        freqNext[nums[n-1]]++;
        
        for(int i = 1;i<n-1;i++) {
            
            if(freqPrev.find(nums[i]*2) != freqPrev.end()) {
                curr[i].first = freqPrev[nums[i]*2];
            }
            if(freqNext.find(nums[n-1-i]*2) != freqNext.end()) {
                curr[n-1-i].second = freqNext[nums[n-1-i]*2];
            }
            
            freqPrev[nums[i]]++;
            freqNext[nums[n-1-i]]++;
        }
        for(auto x:curr) {
       
        res += ((long long)x.second * x.first) % M;
        }
        return (res + M)%M;
    }
};
class Solution {
public:
    struct ComparePair {
    bool operator()(const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
        if (p1.first == p2.first) {
            return p1.second > p2.second; // If first elements are equal, compare by second element
        }
        return p1.first > p2.first; // Otherwise, compare by first element
    }
};

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) 
    {
            std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, ComparePair> pq;
        int ind = 0;
        for(auto x:nums)
        {
            pq.push({x,ind++});
        }
        while(k)
        {
            pair<int,int> temp = pq.top();
            pq.pop();
            pq.push({temp.first*multiplier,temp.second});
            k--;
        }
        vector<int>ans(nums.size());
        while(pq.size())
        {
            ans[pq.top().second] = pq.top().first;
            pq.pop();
        }
        return ans;
    }
};
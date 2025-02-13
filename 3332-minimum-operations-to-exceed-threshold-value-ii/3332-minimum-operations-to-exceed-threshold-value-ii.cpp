class Solution {
public:
    int minOperations(vector<int>& nums, int k) 
    {
        int ans =0;
        priority_queue<long long,vector<long long>,greater<long long>>pq(nums.begin(),nums.end());
        while(pq.size() and pq.top()<k)
        {
            long long x  = pq.top(); pq.pop();
            long long y = pq.top();  pq.pop();
            pq.push(x*2 + y);
            ans++;
        }
        return ans;
    }
};
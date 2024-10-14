class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) 
    {
        priority_queue<int>pq = {nums.begin(),nums.end()};
        long long ans =0;
        while(k)
        {

            int val = pq.top();
            ans+=val;
            pq.pop();
            cout<<val<<" ";
            pq.push(val/3 + !(!(val%3)));
            k--;
        }    
        return ans;
    }
};
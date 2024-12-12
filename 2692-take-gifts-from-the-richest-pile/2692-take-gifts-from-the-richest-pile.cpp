class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) 
    {
        priority_queue<int>pq;
        for(auto x:gifts) pq.push(x);

        long long sum = 0;
        while(k>0)
        {
            int val = pq.top();
            pq.pop();
            pq.push(int(sqrt(val)));
            k--;
        }
        while(pq.size())
            sum+=pq.top(),pq.pop();

        return sum;
    }
};
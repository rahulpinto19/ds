        bool comp(pair<int,int>a,pair<int,int>b)
        {
            return a.first<b.first;
        }
class Solution {
public:

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) 
    {
        vector<pair<int,int>>v;
        for(int i=0;i<difficulty.size();i++)
        {
            v.push_back({difficulty[i],profit[i]});
        } 
        sort(v.begin(),v.end(),comp);

        int val = v[0].second;

        for(auto &x : v)
        {
            x.second = max(x.second,val);
            val = x.second;
        }
        int ans = 0;
        for(auto work:worker)
        {
            int start = 0,end = v.size()-1;
            int temp = -1;
            while(start<=end)
            {
                int mid = (start+end)/2;
                if(v[mid].first > work)
                {
                    end = mid-1;
                }
                else
                {
                    temp = mid;
                    start = mid+1;
                }
            }
                cout<<temp<<" ";
                if(temp!=-1)
                ans+=v[temp].second;
        }
        return ans;
    }
};
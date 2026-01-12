struct CustomCompare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
       

        return a.second > b.second;
    }
};
class Solution {
public:
    static  bool comp(vector<int>&a,vector<int>&b) {
        
        if(a[0] < b[0])
            return 1;
        else if (a[0] == b[0])
            return a[1] < b[1];
        else 
            return 0;
    } 
    int minGroups(vector<vector<int>>& v) {

        sort(v.begin(),v.end(),comp);        

        priority_queue<pair<int, int>, vector<pair<int, int>>, CustomCompare> pq;
        
        for(int i = 0;i<v.size();i++) {

            if(pq.empty()) pq.push({v[i][0],v[i][1]});
            else {
                auto curr = pq.top();
                // cout<<curr.first<<" "<<curr.second<<endl;
                if(curr.first<= v[i][0] and v[i][0] <= curr.second) {
                
                } else pq.pop();

                pq.push({v[i][0],v[i][1]});
            }
        }
        return pq.size();
    }
};



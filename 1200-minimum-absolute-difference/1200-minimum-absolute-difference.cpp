class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        map<int,vector<vector<int>>>mp;

        for(int i = 1;i<arr.size();i++) {

            mp[abs(arr[i-1] - arr[i])].push_back({arr[i-1],arr[i]});
        }
        for(auto x:mp) {
            return x.second;
        }
        return {{-1,-1}};
    }
};
bool comp(int A, int B) {
    
    string a = to_string(A);
    string b = to_string(B);
    
    return a+b > b+a ? 1 : 0 ;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(),comp);
        string ans = "";
        for (auto x : nums) {
            
            ans += to_string(x);
        }
        if(ans[0] == '0')
        return "0";

        return ans;
    }
};
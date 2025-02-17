class Solution {
public:
    vector<vector<int>>ans;
    void help(vector<int>cand,int target,int sum,int pos,vector<int>&temp)
    {
        if(sum == target)
        {
            ans.push_back(temp);
            return;
        }
        if(pos>=cand.size() || sum>target)
        {
            return;
        }
        temp.push_back(cand[pos]);
        help(cand,target,sum + cand[pos],pos,temp);
        temp.pop_back();
        help(cand,target,sum,pos+1,temp);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int>temp;
        help(candidates,target,0,0,temp);    
        return ans;
    }
};
class Solution {
public:
    vector<int> help(vector<int>&code,int k)
    {
        vector<int>ans;
        for(int i=0;i<code.size();i++)
        {
            int temp = 0;
            for(int j=i+1;j<i+k+1;j++)
            {
                temp+=code[j%code.size()];
            }
            ans.push_back(temp);
        }
        return ans;
    }
    vector<int> decrypt(vector<int>& code, int k) 
    {
        if(k==0)
        {
            vector<int>v(int(code.size()),0);
            return v;
        }    
        else if(k<0)
        {
            reverse(code.begin(),code.end());
            vector<int>v = help(code,abs(k));
            reverse(v.begin(),v.end());
            return v;
        }
        else
        {
            return help(code,k);
        }
    }
};
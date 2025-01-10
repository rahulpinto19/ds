class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) 
    {
        vector<int>cnt(26),temp(26);

        for(auto b:B)
        {
            temp = help(b);
            for(int i = 0;i<26;i++)
                cnt[i] = max(cnt[i],temp[i]);
        }    

        vector<string>res;
        for(auto a:A)
        {
            temp = help(a);
            int flag = 0;
            for(int i=0;i<26;i++)
                if(temp[i] < cnt[i])
                    flag = 1;
            if(!flag)
                res.push_back(a);
        }
        return res;
    }
    vector<int>help(string str)
    {
        vector<int>res(26,0);
        for(auto s:str)
        {
            res[s-'a']++;
        }
        return res;
    }
};
class Solution {
public:
    string multiply(string n1, string n2) 
    {
        if(n1=="0"||n2=="0")
        return "0";
        vector<int>v(n1.size()+n2.size(),0);
        for(int i=n1.size()-1;i>=0;--i)
        {
            for(int j=n2.size()-1;j>=0;--j)
            {
                v[i+j+1] += (n1[i]-'0')*(n2[j]-'0');
                v[i+j] += v[i+j+1]/10;
                v[i+j+1]%=10;
            }
        }
       // return "";
        int pos = 0;
        while(pos<v.size() and v[pos]==0)
        ++pos;
        string ans = "";
        while(pos<v.size())
        {cout<<v[pos];ans.push_back(v[pos++]+'0');}
        
        return ans;
    }
};
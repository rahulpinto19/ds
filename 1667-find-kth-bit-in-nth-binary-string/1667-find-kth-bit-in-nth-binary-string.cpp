class Solution {
public:
    string revinvert(string &s)
    {
        int size = s.size();
        while(size--)
        {
            s[size] = s[size] == '0' ? '1' : '0';
        }
        reverse(s.begin(),s.end());
        return s;
    }
    char findKthBit(int n, int k) 
    {
        string s = "0";
        for(int j=n;j>1;j--)
        {
            string temp = "";
            temp = s + '1' + revinvert(s);
            s = temp;
        }   
        return s[k-1];
    }
};
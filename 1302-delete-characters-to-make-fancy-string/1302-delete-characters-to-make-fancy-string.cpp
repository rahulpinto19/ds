class Solution {
public:
    string makeFancyString(string s) 
    {
        string ans = "";
        int cnt = 0;
        char temp;
        for(auto x:s)
        {
            
           if(temp == x)
           cnt++;
           else
           {
            temp = x;
            cnt =1;
           }
           if(cnt<=2)
           ans+=x;
        }    
        return ans;
    }
};
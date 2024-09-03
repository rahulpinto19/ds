class Solution {
public:
    int getLucky(string s, int k) 
    {
        string str = "";
        for(auto x:s)
        {
            str += to_string(int(x-'a' + 1));
        }
        int sum = 0;
        while(k--)
        {
            sum = 0;
            for(auto x:str)
            {
                sum+= int(x-'0');
            }
            str = to_string(sum);
        }
        return sum;
    }
};
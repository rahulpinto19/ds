class Solution {
public:
    int baseToDecimal(string number)
    {
        int val = 0;
        for(auto x:number)
        {
            val<<=1;
            if(x == '1')
            {
                val |=1;
            }
        }
        return val;
    }
    string DecimalToBase(int number,int n)
    {
        string val = "";
        while(number || n)
        {
            val = char('0' + (number%2))  + val;
            number/=2;
            n--;
        }
        return val;
    }
    string findDifferentBinaryString(vector<string>& nums) 
    {
        unordered_set<int>st;
        for(auto x:nums)
        {
            st.insert(baseToDecimal(x));
        }    
        int ans = *(st.begin());
        int n = nums.size();
        while(st.find(ans) != st.end())
        {
            ans = rand() % (int) pow(2,n);
        }
        return DecimalToBase(ans,n);
    }
};
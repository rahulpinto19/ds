class Solution 
{
public:
    vector<int>prime = {0,2,3};
    void createPrime()
    {
        for(int n = 5;n<=1005;n++)
        {
            int flag = 1;
            if (n % 2 == 0 || n % 3 == 0) flag = 0;
            for (int i = 5; i * i <= n; i += 6) 
                {
                    if (n % i == 0 || n % (i + 2) == 0)
                    {
                        flag = 0;
                        break;
                    }
                }
            if(flag)
            prime.push_back(n);
        }
        
    }
    int possible(int val,int comparedVal)
    {
        for(int i=0;i<prime.size();i++)
        {
            if(prime[i] >= val)
            return 0;
            if(comparedVal > val-prime[i])
            {
                return val-prime[i];
            }
        }
        return 0;
    }
    
    bool primeSubOperation(vector<int>& nums) 
    {
        stack<int>s;
        createPrime();
        for(int i=nums.size()-1;i>=0;i--)    
        {
            if(s.empty())
            {
                s.push(nums[i]);
            }
            else
            {
                if(possible(nums[i],s.top()))
                {
                    cout<<possible(nums[i],s.top())<<endl;
                    s.push(possible(nums[i],s.top()));
                }
                else
                return 0;
            }
        }
        return 1;
    }
};
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
   
    int primeNumbers[10001] = {0};
    Solution()
    {
        for(int i=2;i<10001;i++)
        {
            if(isPrime(i))
                primeNumbers[i] =1;
        }
    }
    bool isPrime(int num) 
    {
        
        if (num <= 1) return false;
        for (int i = 2; i <= sqrt(num); ++i) {
            if (num % i == 0) return false;
        }
        return true;
    }
   
    
    int minOperations(int n, int m) 
    {

        if(primeNumbers[n] or primeNumbers[m]) return -1;
        
        if(n==m) return n;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        set<int>s;

        pq.push({n,n});

        while(pq.size())
        {
            auto [steps,curr] = pq.top();
            pq.pop();

            if(s.find(curr) != s.end()) continue;
            s.insert(curr);

            if(curr == m) return steps;
            string str = to_string(curr);

            for(int i=0;i<str.size();i++)
            {
                if(str[i] !='0')
                {
                    str[i]--;
                    int next = stoi(str);
                    if(!primeNumbers[next])
                    {
                        pq.push({steps+next,next});
                    }
                    str[i]++;
                }
            }
              for(int i=0;i<str.size();i++)
            {
                if(str[i] !='9')
                {
                    str[i]++;
                    int next = stoi(str);
                    if(!primeNumbers[next])
                    {
                        pq.push({steps+next,next});
                    }
                    str[i]--;
                }
            }
        }
        return -1;
    }
};

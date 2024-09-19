class Solution {
public:
    vector<int> diffWaysToCompute(string ex) 
    {
        vector<int>res;

        for(int i = 0;i<ex.size();i++)
        {
            if(ex[i]>'9' || ex[i] < '0')
            {
                vector<int>l = diffWaysToCompute(ex.substr(0,i)); 
                vector<int>r = diffWaysToCompute(ex.substr(i+1)); 

                for(auto x:l)
                {
                    for(auto y:r)
                    {
                        if(ex[i] == '-')
                        {
                            res.push_back(x-y);
                        }
                        else if(ex[i] == '+')
                        {
                            res.push_back(x+y);
                        }
                        else
                        {
                            res.push_back(x*y);
                        }
                    }
                }
            }
        }    
        if(res.size() == 0)
        res.push_back(stoi(ex));

        return res;
    }
};
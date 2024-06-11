class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
    {
        vector<int>t1,t2;
        
        for(auto x:arr1)
        {
            int flag = 0;
            for(auto y:arr2)
            {
                if(x == y)
                {
                    flag = 1;break;
                }
            }
            if(!flag)
            t2.push_back(x);
        }
        
        for(auto x:arr2)
        {
            for(auto y:arr1)
            {
                if(x == y)
                {
                    t1.push_back(x);
                }
            }
            
        }
        sort(t2.begin(),t2.end());
        t1.insert(t1.end(),t2.begin(),t2.end());
        return t1; 
    }
};
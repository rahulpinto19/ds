class Solution {
public:
    bool canArrange(vector<int>& arr, int k) 
    {
        int count=0;
        unordered_map< long,long>m;
        for(int i=0;i<arr.size();i++)
        {
            int a=(arr[i]%k+k)%k;
            if(!a)
            {
                if(m.find(a)!=m.end())
                {
                    count++;
                    m[a]--;
                    if(!m[a])
                    m.erase(a);
                }
                else
                m[a]++;
            }
            else if(m.find(k-a)!=m.end())
            {
                count++;
                m[k-a]--;
                if(!m[k-a])
                m.erase(k-a);
            }
            else
            m[a]++;
        }
        if(count>=arr.size()/2)
        return true;
        return false;
    }
};
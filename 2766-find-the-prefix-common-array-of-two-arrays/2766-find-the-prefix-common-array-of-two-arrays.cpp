class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) 
    {
        vector<int>ans;
        int count=0;
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<=i;j++)
            {
                for(int k=0;k<=i;k++)
                {
                    if( A[j]==B[k])
                        count++;
                }
            }
            ans.push_back(count);
            count=0;
        }
        return ans;
    }
};
class Solution {
public:
    bool canChange(string start, string target) 
    {
        int i = 0,j = 0,n = start.size();

        while(i<n || j<n)
        {
            while(i<n and start[i]== '_')i++;
            while(j<n and target[j]== '_')j++;

            if (i>=n || j>=n) return i==j;

            if (start[i] != target[j]) return false;

            if (start[i] == 'L' and j>i) return false;

            if (start[i] == 'R' and j<i) return false;

            i++;j++;

        }    
        return true;
    }
};
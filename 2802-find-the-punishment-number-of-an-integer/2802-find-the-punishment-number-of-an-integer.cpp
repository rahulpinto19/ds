class Solution {
public:
    void partition(int target,bool &f,vector<int>&numArray,int curSum,int prevSum,int pos)
    {
        if(f)
            return;
        if(pos >= numArray.size())
        {
            if(curSum + prevSum == target)
                f = 1;
            return;
        }
        partition(target,f,numArray,curSum + prevSum,numArray[pos],pos+1);
        partition(target,f,numArray,curSum ,prevSum*10 + numArray[pos],pos+1);

    }
    void help(int number,bool &f)
    {
        int num = number;
        number*=number;
        vector<int>numArray;
        while(number)
        {
            numArray.push_back(number%10);
            number/=10;
        }
        reverse(numArray.begin(),numArray.end());
        partition(num,f,numArray,0,0,0);
      
        return ;
    }
    int punishmentNumber(int n) 
    {
        int ans = 0;
        for(int i = 1;i<=n;i++)
        {
            bool f = false;
            help(i,f);
            if(f)
                ans+=(i*i);
        }    
        return ans;
    }
};
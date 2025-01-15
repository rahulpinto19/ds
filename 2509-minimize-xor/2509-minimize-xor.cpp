class Solution {
public:
    int minimizeXor(int num1, int num2) 
    {
        int noofBits = 0;
        while(num2)
        {
            noofBits+=(num2&1);
            num2/=2;
        } 
        cout<<"nofBits:"<<noofBits<<endl;
        int reqNumber = 0;
        for(int i = 31;i>=0 and noofBits;i--)
        {
            if((num1>>i)&1)
                {reqNumber|=(1<<i);noofBits--;}
        }   
        cout<<"nofBits:"<<noofBits<<endl;

        for(int i = 0;i<32 and noofBits;i++)
        {
            if(!((reqNumber>>i)&1))
                {reqNumber|=(1<<i);noofBits--;}
        }
        cout<<"nofBits:"<<noofBits<<endl;

        return reqNumber;
    }
};
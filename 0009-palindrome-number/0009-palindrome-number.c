bool isPalindrome(int x) 
{
    if(x<0) return false;
    long  var = x;
    long sum =0;
    while(x!=0)
    {
        int rem = x%10;
        sum = sum*10 + rem;
        x/=10;
    }
    return var ==  sum;
}
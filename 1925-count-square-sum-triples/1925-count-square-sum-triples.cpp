class Solution {
public:
    int countTriples(int n) {
        
        int cnt = 0;
        for(int i = 1;i<n;i++) {
            
            for(int j = 1;j<n;j++) {
                
                long long k = sqrt(i*i + j*j);
                // cout<<i<<" "<<j<<endl;
                if(k*k ==  i*i + j*j and k <= n) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
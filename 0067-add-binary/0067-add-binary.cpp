class Solution {
public:
    string addBinary(string a, string b) {
        
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());

        int carry = 0;

        string ans = "";

        int i = 0,j = 0;
        while(i<a.size() and j<b.size()) {

            int curr = a[i] -  '0' + b[j] - '0' + carry;

            carry = curr/2;
            i++;j++;
            ans += '0' + (curr%2); 
        }
        while(i<a.size()){
            int curr = a[i] - '0' + carry;
            carry = curr/2;
            i++;
            ans+= '0' + (curr%2);
        }
         while(j<b.size()){
            int curr = b[j] - '0' + carry;
            carry = curr/2;
            j++;
            ans+= '0' + (curr%2);
        }
        if(carry) ans+='1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
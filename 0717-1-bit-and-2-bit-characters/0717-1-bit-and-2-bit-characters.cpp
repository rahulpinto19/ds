class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        
        int ptr = 0;
        while(ptr<bits.size()-1) {

            ptr = bits[ptr] == 0 ? ptr+1 : ptr+2; 
        }

        return ptr == bits.size()-1;
    }
};

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        
        int ptr = 0;
        while(ptr<bits.size()) {


            if(bits[ptr] == 0) 
            {
                if(ptr == bits.size()-1) return true;
                ptr++;
                continue;
            }
            else {

                ptr+=2;
            }
        }

        return ptr == bits.size()-1;
    }
};

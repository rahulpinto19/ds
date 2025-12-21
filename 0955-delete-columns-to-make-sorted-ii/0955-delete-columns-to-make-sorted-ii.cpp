class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        
        int deletion = 0;
        vector<bool>sorted(strs.size(),false);

        for(int j = 0;j<strs[0].size();j++) {

            bool bad = false;            
            for(int i = 0;i<strs.size()-1;i++) {

                if(!sorted[i] and strs[i][j] > strs[i+1][j]) {

                    bad = true;
                    break;
                }
            }

            if(bad) {
                deletion++;
            }
            else {
                for(int i = 0;i<strs.size()-1;i++) {

                    if(strs[i][j] < strs[i+1][j]) {
                        sorted[i] = true;
                    }
                }
            }
        }
        return deletion;
       
    }
};

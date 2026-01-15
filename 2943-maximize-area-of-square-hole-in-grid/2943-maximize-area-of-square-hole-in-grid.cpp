class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        
        // return 1;
        if(hBars.size() == 0 or vBars.size() == 0)   
            return 1;
            
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int hCons = 1,vCons = 1;

        int cnt = 1;
        for(int i = 1;i<hBars.size();i++) {
            
            if(hBars[i] - hBars[i-1] == 1 ) {cnt++; hCons = max(hCons,cnt);}
            else cnt = 1;
        }
        cnt = 1;
        for(int i = 1;i<vBars.size();i++) {
            if(vBars[i] - vBars[i-1] == 1) {cnt++;vCons = max(vCons,cnt);}
            else cnt = 1;
        }

        if(hCons < vCons) {
            return (hCons+1) * (hCons+1);
        } 
        return (vCons+1) * (vCons+1);
    }
};
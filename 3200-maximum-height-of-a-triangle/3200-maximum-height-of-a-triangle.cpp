class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        
        int h1 = 0;
        int req = 1;
        int take = 0;
        vector<int>arr(2,0);
        arr[0] = blue;
        arr[1] = red;
        while(req <= arr[take]) {
            
            arr[take]-=req;
            req++;
            h1++;
            take = !take;
        }
        int h2 = 0;
        req = 1;
        take = 0;
        arr[0] = red;
        arr[1] = blue;
         while(req <= arr[take]) {
            
            arr[take]-=req;
            req++;
            h2++;
            take = !take;
        }
        return max(h1,h2);
    }
};

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {


        double low = 0,high = 0;
        double tArea = 0;
        for(auto &x:squares) {

            int l = x[2] ,y = x[1];
            tArea += (double)(l)*l;
            high = max(high,double(l+y));
        }
        double area ;
        auto help = [&](double mid) -> bool {
            area = 0;
            for(auto &x:squares){
            
            double y = x[1],l = x[2];
            if(y < mid) {
                area += l * min(mid-y,double(l));
            }
            }
            return area < tArea/2.0;
        };

        double eps = 1e-5;
        double mid;
        while(abs(high - low) > eps) {

            mid = (low + high)/2;

            if(help(mid)) {
                low = mid;
            }else {
                high = mid;
            }
        }
        return high;
    }
};



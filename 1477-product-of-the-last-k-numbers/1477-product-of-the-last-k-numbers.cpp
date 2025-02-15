class ProductOfNumbers {
public:
    vector<long long>pp = {1};
    ProductOfNumbers() {
        
    }
    
    void add(int num) 
    {
       if(num == 0) pp  = {1};
       else pp.push_back(pp.back()*num);
    }
    
    int getProduct(int k) 
    {
        if(pp.size() <=k ) return 0;
        return pp.back() / pp[pp.size()-k-1];
    }
};
// [3,0,2,5,4,8]

// [0,0,2,10,40,320]
/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
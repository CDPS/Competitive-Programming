class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        
        int product = 1, productZeros=1;
        int n = a.size();
        int zeros = 0;
        
        for(int i=0;i < n ; i++){
            if(a[i]==0)
                zeros++;
            if(zeros > 1)
                productZeros = 0;
            if(a[i] != 0)
                productZeros*=a[i];
            product *= a[i];
        }
        
        for(int i=0;i < n ; i++)
            a[i] = (a[i]==0)? productZeros : product/a[i];
        return a;
    }
};
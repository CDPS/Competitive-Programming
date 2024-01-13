class Solution {
public:
    int jump(vector<int>& a) {
        
        int n = a.size();
        vector<int> mini (n,1000000);
        mini[0] = 0;

        for(int i=0;i<n-1;i++){
            for(int j=1;  j<=a[i] && i+j<n;j++)
                mini[i + j] = min( mini[i + j], mini[i] + 1 );
        }
        return mini[n-1];
    }
};
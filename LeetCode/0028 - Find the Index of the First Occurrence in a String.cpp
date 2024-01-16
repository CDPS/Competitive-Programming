class Solution {
public:
    int strStr(string a, string b) {
        
        int n = a.size(), m = b.size();
        if(m > n)
            return -1;

        int res = -1;
        for(int i=0;i<=n-m;i++){
            bool ans = true;
            for(int j=0;j<m && ans;j++)
                ans = a[i+j] == b[j];
            if(ans) {res =i; break;}
        }
        return res;
    }
};
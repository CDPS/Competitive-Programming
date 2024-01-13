class Solution {
public:
    bool canJump(vector<int>& a) {
        
        int n = a.size();
        vector<bool> can(n,false);
        can[0] = 1;

        for(int i=0;i<n-1;i++){
            if(can[n-1])
                break;
            if(can[i])
                for(int j=1;  j<=a[i] && i+j<n;j++)
                    can[i + j] = true;
        }
        return can[n-1];
    }
};
class Solution {
public:

    int getBitSize(int x){
        int ans = 0;
        while(x)
            x/=2, ans++;
        return ans;
    }

    int rangeBitwiseAnd(int left, int right) {
        if(left == right) return left;
        if(left == 0) return 0;
        if(getBitSize(left)!=getBitSize(right)) return 0;
        int ans = left;
        for(uint i=left;i<=right;i++)
            ans &=i;
        return ans;
    }
};
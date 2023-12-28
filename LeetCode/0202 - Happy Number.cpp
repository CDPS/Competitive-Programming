class Solution {
public:

    int getHappyNumber(int n){
        int res = 0;
        while(n>0){
            int d = n%10;
            res+= (d*d);
            n/=10;
        }
        return res;
    }

    bool isHappy(int n) {
        
        bool ans = true;
        unordered_set<int> st;

        while(n!=1){
            n = getHappyNumber(n);
            if(st.count(n)){
                ans = false;
                break;
            }
            st.insert(n);
        }

        return ans;
    }
};
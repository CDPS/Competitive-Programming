class Solution {
public:
    int hIndex(vector<int>& a) {
        
        int maxi = 0;
        int n = a.size();
        for(int i=0;i<n;i++)
            maxi = max(maxi,a[i]);
        sort(a.begin(), a.end());

        for(int i=maxi;i>=0;i--){   
            auto find = lower_bound(a.begin(), a.end(), i);
            int index = (find - a.begin());
            if(n-index >= i)
                return i;
        }
        return 0;
    }
};
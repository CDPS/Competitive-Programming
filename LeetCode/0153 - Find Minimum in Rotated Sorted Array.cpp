class Solution {
public:
    int findMin(vector<int>& a) {
        
        int l = 0, h = a.size() -1;
        int mini = 5001;

        while(l <= h){
            int m = (l+h)/2;
            if(a[l] < mini) mini = a[l];
            if(a[l] <= a[m] && a[m]> a[h])
                l = m + 1;
            else if(a[l]> a[m] && a[m] < a[h])
                h = m ;
            else
                h = m - 1;
        }

        return min(mini, a[l]);
    }
};
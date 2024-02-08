class Solution {
public:

    int binarySearch(vector<int>& a, int l, int h, int t){
        while(l <= h){
            int m = (l+h)/2;
            if(a[m] == t) return m;

            if(a[l]<= a[m])
                if(a[l]<= t && t < a[m]) h = m - 1;
                else l = m + 1;
            else
                if(a[m]< t && t <= a[h]) l = m + 1;
                else h = m - 1;
        }
        return -1;
    }

    int search(vector<int>& a, int target) {
        return binarySearch(a,0, a.size()-1, target);
    }
};
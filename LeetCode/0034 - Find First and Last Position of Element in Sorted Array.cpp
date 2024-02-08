class Solution {
public:
    vector<int> searchRange(vector<int>& a, int target) {
        
        auto it_s = lower_bound(a.begin(), a.end(), target);
        auto it_e = upper_bound(a.begin(), a.end(), target);

        int idx_s = it_s == a.end()? -1: it_s - a.begin();
        int idx_e = it_e == a.end()? a.size()-1: it_e - a.begin() -1;
        
        int s = (idx_s !=-1 && a[idx_s]== target)? idx_s : -1;
        int e = (idx_e !=-1 && a[idx_e]== target)? idx_e : -1;

        return {s,e};
    }
};
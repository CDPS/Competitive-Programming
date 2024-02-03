class Solution {
public:

    int lowerBound(vector<vector<int>>& a, int x){
        int l=0, h = a.size()-1, m;
        while(l<h){
            m = l + ( (h-l+1)/2 );
            if(a[m][0] == x) return m;
            if(a[m][0] > x)
                h = m-1;
            else l = m;
        }
        return l;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row  = lowerBound(matrix,target);
        auto itr = lower_bound(matrix[row].begin(), matrix[row].end(), target);
        return itr != matrix[row].end() && *itr == target;
    }
};
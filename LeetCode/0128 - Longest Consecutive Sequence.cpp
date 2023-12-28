class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n<=1)
            return n;

        set<int> st;
        for(int i=0;i<n;i++)
            st.insert(nums[i]);

        int ans = 1, partial = 1;
        set<int>::iterator it = st.begin();
        int previous = *it;
        it++;

        while(it!=st.end()){
            int current = *it;
            cout << previous << " " << current << "\n";
            if(current != previous +1)
                partial = 0;
            partial++;
            ans = max( ans, partial);
            previous = current;
            it++;
        }

        return ans;
    }
};
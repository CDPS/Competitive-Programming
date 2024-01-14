class Solution { 
public:
    string longestCommonPrefix(vector<string>& a) {
        
        int n = a.size();
        int mini = 300;
        for(int i =0; i < n; i ++)
            mini = min(mini, (int) a[i].size());
        
        bool keepGoing = true;
        string ans = "";
        for(int i=0;i<mini && keepGoing;i++){
            char first = a[0][i];
            for(int j=1;j<n && keepGoing;j++)
                keepGoing = a[j][i]==first;
            if(keepGoing)
                ans+=first;
        }

        return ans;
    }
};
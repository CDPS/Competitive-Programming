#include <bits/stdc++.h>

using namespace std;


int main(){

    int n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;

    int mini = 1000000; vector<int> ans;

    for(int i=0;i<m-n+1;i++){

        vector<int> par;int res=0;

        for(int j=0;j<n;j++)
            if(s[j]!=t[i+j])
                res++, par.push_back(j+1);

        if(res<mini) mini=res, ans=par;
    }

    cout << mini << "\n";
    for(int i=0;i<ans.size();i++){
        if(i==0) cout << ans[i];
        else cout << " " << ans[i];
    }
    return 0;
}

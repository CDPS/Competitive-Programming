#include <bits/stdc++.h>

using namespace std;

int a[100002];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    cin >> t;

    while(t--){

        cin >> n;

        for(int i=0;i<n;i++) cin >> a[i+1];
        a[0]   = (a[1]> a[2])?0:n+1;
        a[n+1] = (a[n]< a[n-1])?n+1:0;

        vector<int> ans;
        for(int i=1;i<=n;i++)
             if( (a[i] > a[i-1] && a[i] > a[i+1]) ||
                 (a[i] < a[i-1] && a[i] < a[i+1]))
                    ans.push_back(a[i]);

        cout << ans.size() << "\n";
        for(int i=0;i<ans.size();i++)
            cout << ans[i] << " \n"[i== ans.size()-1];
    }
    return 0;
}

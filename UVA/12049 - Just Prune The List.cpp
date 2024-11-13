#include<bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t,n,m,x;
    cin >> t;

    while(t--){
        cin >> n >> m;
2
        unordered_map<int, int> a,b;
        set<int>st;

        while(n--)
            cin >> x, st.insert(x), a[x]++;

        while(m--)
            cin >> x, st.insert(x), b[x]++;

        int ans = 0;
        for(auto it= st.begin();it!=st.end();it++)
            ans += abs(a[*it]-b[*it]);

        cout << ans << "\n";
    }
    return 0;
}

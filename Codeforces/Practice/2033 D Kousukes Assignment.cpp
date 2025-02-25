#include <bits/stdc++.h>

using namespace std;

int a[100000];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n;
    cin >> t;

    while(t--){

        cin >> n;
        for(int i=0;i<n;i++) cin >> a[i];

        set<int> st; st.insert(0);

        int acc = 0, ans = 0;
        for(int i=0;i<n;i++){
            acc+=a[i];
            if(st.count(acc)) ans++;
            cout << acc << " " << ans << "\n";
            st.insert(acc);
        }
        cout << ans << "\n";
    }
    return 0;
}

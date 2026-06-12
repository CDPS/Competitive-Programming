#include <bits/stdc++.h>

using namespace std;

int t, n;
int a[300000];

int solve(){

    cin >> n;
    for(int i = 0; i < n; i++ )
        cin >> a[i];

    vector<int> st; st.push_back(a[0]);

    int ans = 1;
    for(int i=1;i<n;i++){

        while( !st.empty() && st.back() >= a[i])
            st.pop_back();

        if(!st.empty() && st.back()== a[i]-1 ){
            st.push_back(a[i]);
            continue;
        }

        ans++;
        st.clear();
        st.push_back(a[i]);
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}

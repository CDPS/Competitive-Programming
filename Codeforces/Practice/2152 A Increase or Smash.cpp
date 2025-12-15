#include <bits/stdc++.h>

using namespace std;

int t, n, x;

int solve(){

    cin >> n;
    set<int> st;
    for(int i=0;i<n;i++)
        cin >> x, st.insert(x);

    int m = st.size();

    return m + (m-1);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}

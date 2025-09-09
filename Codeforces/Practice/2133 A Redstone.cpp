#include <bits/stdc++.h>

using namespace std;

int n, x;

bool solve(){

    cin >> n;

    set<int> st;

    bool ans = false;
    for(int i=0;i<n;i++)
        cin >> x, ans |= st.count(x), st.insert(x);

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        cout << ( solve()? "YES" : "NO" ) << "\n";

    return 0;
}

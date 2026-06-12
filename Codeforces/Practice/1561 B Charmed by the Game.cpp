#include <bits/stdc++.h>

using namespace std;

int t, a, b;

set<int> st;

void f(int sa, int sb){
    for(int x=max(0, a-sb); x<= min(a, sa);x++)
        st.insert( a + sa - (2*x) );
}

void solve(){

    st.clear();
    cin >> a >> b;

    int n = a + b;

    f(n/2 + n%2, n/2);
    f(n/2, n/2 + n%2);

    cout << st.size() << "\n";
    for(int x : st)
        cout << x << " ";
    cout << "\n";
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}

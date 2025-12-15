#include <bits/stdc++.h>

using namespace std;

int t, n, x;

int solve(){

    cin >> n;

    set<int> st;
    for(int i=0;i<=n;i++)
        st.insert(i);

    for(int i=0;i<n;i++){
        cin >> x;
        if(st.count(x))
            st.erase(x);
    }

    return *st.begin();
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}


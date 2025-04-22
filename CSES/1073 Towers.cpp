#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    multiset<int> st;
    int n, x, ans  = 0;
    cin >> n;

    st.insert(0);
    for(int i=0;i<n;i++){
        cin >> x;

        auto it = st.upper_bound(x);
        if(it != st.end()) st.erase(it);
        else ans++;

        st.insert(x);
    }

    cout << ans  << "\n";

    return 0;
}

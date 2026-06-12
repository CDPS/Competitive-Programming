#include <bits/stdc++.h>

using namespace std;

int t = 1, n, ai;

void solve(){

    cin >> n;

    multiset<int> st;
    for(int i = 0; i < n*n ; i++)
        cin >> ai,  st.insert(ai);

    vector<int> ans;
    for(int i = 0; i < n; i++){

        auto it_next = st.rbegin();
        for(int j=0; j < ans.size(); j++ ){
            st.erase(st.find( __gcd(*it_next, ans[j]) ));
            st.erase(st.find( __gcd(*it_next, ans[j]) ));
        }
        ans.push_back(*it_next);
        st.erase(st.find(*it_next));
    }

    for(int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i== n-1];
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}

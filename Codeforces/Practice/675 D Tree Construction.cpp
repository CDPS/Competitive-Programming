#include <bits/stdc++.h>

using namespace std;

int oo = 1e9 + 7;

int t = 1, n, ai;
void solve(){

    cin >> n >> ai;

    set<int> st; st.insert(ai);

    map<int, pair<int,int> > mp;

    mp[ai] = {-1, -1};
    mp[oo] = {oo, oo};


    vector<int> ans (n);
    for(int i=1; i <n; i++ ){

        cin >> ai;

        auto it_x = st.upper_bound(ai);
        auto it_y = st.upper_bound(ai);

        int x  = (it_x != st.end())? *it_x  : oo;
        int y  = (it_y != st.begin())? *(--it_y) : oo;

        if(mp[x].first == -1 )
            ans[i] = x, mp[x].first = ai;
        else
            ans[i] = y, mp[y].second = ai;

        st.insert(ai);
        mp[ai] = {-1, -1};
    }

    for(int i=1;i < n;i++)
        cout << ans[i] << " \n"[i==n-1];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int t, n, x;

void solve(){

    cin >> n;

    set<int> st;

    bool odd = false;
    bool even = false;
    for(int i=0;i<n;i++){
        cin >> x;
        st.insert(x);

        if(x%2) odd = true;
        else   even = true;
    }

    if(odd && even){
        cout << -1 << "\n";
        return;
    }

    vector<int> ans;
    while(st.size() > 1){

        x = (*st.begin() + *st.rbegin())/2;

        ans.push_back(x);
        set<int> curr;
        for(auto it = st.begin(); it != st.end(); it++)
            curr.insert( abs(*it -x) );
        st = curr;
    }

    if(*st.begin()!=0)
        ans.push_back(*st.begin());

    cout << ans.size() << "\n";
    for(int i=0;i<ans.size();i++)
        cout << ans[i] << " ";
    cout << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}

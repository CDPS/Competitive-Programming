#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;

void solve(){

    cin >> n;
    vector<int> v(n), a(n);

    for(int i=0;i<n;i++)
        cin >> a[i], v[i] = a[i];

    v.erase(unique(v.begin(), v.end()), v.end());

    if(v[v.size()-1] == 1){
        cout << "NO" << "\n";
        return;
    }

    stack<pair<int,int>> st;

    for(int i=0, blacks = 0, last = 0;i<n;i++){
        if(a[i])
            blacks++;
        if(i > 0 && a[i] > a[i-1])
            st.push({blacks-1, i-last}), blacks =1, last = i;
        if(i==n-1)
            st.push( {blacks, n-last});
    }

    cout << "YES" << "\n";
    int i = 0;
    while(!st.empty()){
        auto u = st.top(); st.pop();
        for(int j=0; j < u.second - (u.first > 0);j++)
            cout << 0 << " \n"[i==n-1];
        if(u.first>0)
            cout << u.first << " \n"[i==n-1];
        i++;
    }

}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}

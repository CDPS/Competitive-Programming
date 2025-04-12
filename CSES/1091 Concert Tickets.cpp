#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n, m, x;
    cin >> n >> m;

    multiset<int> st;
    for(int i=0;i<n;i++)
        cin >> x, st.insert(x);

    while(m--){
        cin >> x;
        auto it = st.upper_bound(x);
        if(it == st.begin())
            cout << -1 << "\n";
        else
            cout << *(--it) << "\n", st.erase(it);
    }

    return 0;
}

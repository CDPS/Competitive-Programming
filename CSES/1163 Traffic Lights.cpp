#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n, m, x;

    cin >> n >> m;

    set<int> range = {0, n};
    multiset<int> st = {n};

    while(m--){

        cin >> x;

        auto l = range.lower_bound(x); --l;
        auto r = range.upper_bound(x);

        st.insert(x-*l);
        st.insert(*r-x);
        st.erase(st.find(*r-*l));
        range.insert(x);

        cout << *st.rbegin() << " ";
    }

    return 0;
}

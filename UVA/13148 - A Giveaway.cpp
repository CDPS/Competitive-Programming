#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    unordered_set<int>st;
    st.insert(1);
    st.insert(64);
    st.insert(729);
    st.insert(4096);
    st.insert(15625);
    st.insert(46656);
    st.insert(117649);
    st.insert(262144);
    st.insert(531441);
    st.insert(1000000);
    st.insert(1771561);
    st.insert(2985984);
    st.insert(4826809);
    st.insert(7529536);
    st.insert(11390625);
    st.insert(16777216);
    st.insert(24137569);
    st.insert(34012224);
    st.insert(47045881);
    st.insert(64000000);
    st.insert(85766121);

    int n;
    while(cin >> n && n)
        cout << ( (st.count(n))?  "Special" : "Ordinary" ) << "\n";
    return 0;
}

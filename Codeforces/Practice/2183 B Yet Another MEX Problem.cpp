
#include <bits/stdc++.h>

using namespace std;

int t, n, k;
int a[200000];

set<int> st;

void add(int x){
    if(st.count(x));
        st.erase(x);
}

int solve(){

    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> a[i];

    st.clear();
    for(int i=0;i<=n;i++) st.insert(i);

    for(int i=0;i<n;i++) add(a[i]);

    int mex= *st.begin();
    return min(k-1, mex );
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n" ;

    return 0;
}


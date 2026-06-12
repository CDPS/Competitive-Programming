#include <bits/stdc++.h>

using namespace std;

int t, n;
int a[200000];

int solve(){

    cin >> n;

    multiset<int> st;
    for(int i=0; i < n; i++)
        cin >> a[i], st.insert( a[i]);

    int ans = 0;
    for(int i = n - 1; i>=0; i--){
        ans += a[i] == *st.rbegin();
        st.erase( st.find(a[i]));
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n" ;

    return 0;
}

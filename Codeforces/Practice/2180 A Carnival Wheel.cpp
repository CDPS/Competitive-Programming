#include <bits/stdc++.h>

using namespace std;

int t, n, a, b;

int solve(){

    cin >> n >> a >> b;

    set<int> st;

    int ans = a;
    while(!st.count(a)){
        st.insert(a);
        ans = max(ans, a);
        a =  (a%n + b%n )%n;
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;

    while(t--)
        cout << solve() << "\n";

    return 0;
}

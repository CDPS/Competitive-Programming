#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pii pair<int,int>

int t = 1, n, m, ti, ri;

int a[200000];

void solve(){

    cin >> n >> m;

    int maxi = -1;
    for(int i=0;i<n;i++) cin >> a[i];

    stack<pii> st;
    while(m--){
        cin >> ti >> ri;
        ri--;
        while (!st.empty() && st.top().s <= ri )
            st.pop();
        st.push({ti, ri});
        maxi = max(ri, maxi);
    }

    vector<int> record (n);
    for(int i=0;i < n && ! st.empty(); i++){
        record[i] = st.top().f;
        if( i == st.top().s )
            st.pop();
    }
    sort(a, a + maxi + 1);

    vector<int> ans(n);
    for(int i=n-1; i  > maxi; i--)
        ans[i] = a[i];

    int i = 0, j = maxi;
    for(int k = maxi; k>=0;k--)
        ans[k] = (record[k] == 2) ? a[i++] : a[j--];

    for(int i=0; i < n; i++)
        cout << ans[i] << " \n"[i==n-1];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    while(t--)
        solve();

    return 0;
}

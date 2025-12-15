#include <bits/stdc++.h>

using namespace std;

int t, n;
int a[200001];

int solve(){

    cin >> n;

    set<int> st;

    for(int i=1;i<=n;i++) st.insert(i);

    for(int i=1;i<=n;i++)
        cin >> a[i], st.erase(a[i]);

    auto it = st.rbegin();
    for(int i=1;i<=n && it!=st.rend();i++)
        if(a[i]==0)
            a[i] = *(it++);

    int l = 0, r= 0;
    for(int i=1;i<=n;i++)
        if(a[i] != i){
            l = i; break;
        }

    for(int i=n;i>=0;i--)
        if(a[i] != i){
            r = i; break;
        }

    return (l==0 && r==0)? 0 : r-l+1;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}

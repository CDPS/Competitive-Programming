#include <bits/stdc++.h>

using namespace std;

int n, t, k;
int a[200000];

void solve(){

    cin >> n >> k;

    set<int> st;
    for(int i=0;i < n; i++)
        cin >> a[i], st.insert(a[i]);

    sort(a, a + n);

    set<int> b;
    map<int, int> mp;
    for(int i=0;i<n;i++){

        if(k/a[i] > n ){
            cout << -1 << "\n";
            return;
        }

        for(int j=a[i]; j<=k;j+=a[i]){
            if(!st.count(j)){
                cout << -1 << "\n";
                return;
            }

            if(mp.find(j) == mp.end())
                mp[j] = a[i], b.insert(a[i]);
        }
    }

    cout << b.size() << "\n";
    for(auto it = b.begin(); it != b.end(); it++)
        cout << *it << " ";
    cout << "\n";

}
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}

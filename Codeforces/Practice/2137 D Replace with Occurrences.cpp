#include <bits/stdc++.h>

using namespace std;

int t, n, x;

void solve(){

    cin >> n;

    vector<int> a(n+1,0), b(n);
    for(int i=0;i<n;i++)
        cin >> b[i], a[b[i]]++;

    for(int i=1;i<=n;i++)
        if(a[i]> 0 && a[i]%i!=0){
            cout << -1 << "\n"; return;
        }

    map<int, int> mp;
    for(int i=0, curr = 1;i<n;i++){
        if(a[b[i]]!=0 && a[b[i]]%b[i]==0)
                mp[b[i]]=curr++;
        cout << mp[b[i]]<< " \n"[i==n-1];
        a[b[i]]--;
    }
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}

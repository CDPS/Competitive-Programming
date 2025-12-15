#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

bool solve(){

    cin >> n ;

    vector<pair<int,int>> a(n);

    map<int, int> mp;
    for(int i=0;i<n;i++)
        cin >> a[i].first >> a[i].second,  mp [ a[i].first ] = a[i].second ;

    for(int i=0;i<n;i++){
        int traget = a[i].first + a[i].second;
        if(mp.count(traget) &&  traget - mp[a[i].first + a[i].second] == a[i].first  )
            return true;
    }
    return false;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    cout << ( solve() ? "YES" : "NO" ) << "\n";

    return 0;
}

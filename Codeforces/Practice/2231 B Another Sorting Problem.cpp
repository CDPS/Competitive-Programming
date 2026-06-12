#include <bits/stdc++.h>

using namespace std;

int t, n;

bool solve(){

    cin >> n;

    vector<int> a(n);
    for(int i=0; i < n; i++ ) cin >> a[i];

    int maxi = -1e9;
    for(int i=1; i < n; i++)
        maxi = max(maxi, a[i-1]-a[i]);

    for(int i=1; i <n; i++)
         if(a[i] < a[i-1] )
            a[i] += maxi;

    return is_sorted(a.begin(), a.end());
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << (solve()? "YES" : "NO") << "\n";

    return 0;
}



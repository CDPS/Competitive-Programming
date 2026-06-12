#include <bits/stdc++.h>

using namespace std;

int t, n, s, k, x;

bool solve(){

    cin >> n >> s >> k;

    int sum = 0;
    for(int i=0;i<n;i++)
        cin >> x, sum+=x;

    if(sum > s) return false;

    return (s-sum)%k==0;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << (solve()? "YES" : "NO") << "\n";

    return 0;
}

